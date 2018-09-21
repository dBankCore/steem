FROM phusion/baseimage:0.9.19

ARG DPAY_STATIC_BUILD=ON
ENV DPAY_STATIC_BUILD ${DPAY_STATIC_BUILD}

ENV LANG=en_US.UTF-8

RUN \
    apt-get update && \
    apt-get install -y \
        autoconf \
        automake \
        autotools-dev \
        bsdmainutils \
        build-essential \
        cmake \
        doxygen \
        git \
        libboost-all-dev \
        libreadline-dev \
        libssl-dev \
        libtool \
        liblz4-tool \
        ncurses-dev \
        pkg-config \
        python3 \
        python3-dev \
        python3-jinja2 \
        python3-pip \
        nginx \
        fcgiwrap \
        awscli \
        jq \
        wget \
        gdb \
    && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
    pip3 install gcovr

RUN \
    git clone https://github.com/dpays/dpay.git -b 0.20.0-release /usr/local/src/dpay && \
    cd /usr/local/src/dpay && \
    git checkout stable && \
    git submodule update --init --recursive && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr/local/dpayd-full \
        -DCMAKE_BUILD_TYPE=Release \
        -DLOW_MEMORY_NODE=OFF \
        -DCLEAR_VOTES=OFF \
        -DSKIP_BY_TX_ID=ON \
        -DBUILD_DPAY_TESTNET=OFF \
        -DDPAY_STATIC_BUILD=${DPAY_STATIC_BUILD} \
        .. \
    && \
    make -j$(nproc) && \
    make install && \
    rm -rf /usr/local/src/dpay

RUN \
    apt-get remove -y \
        automake \
        autotools-dev \
        bsdmainutils \
        build-essential \
        cmake \
        doxygen \
        dpkg-dev \
        git \
        libboost-all-dev \
        libc6-dev \
        libexpat1-dev \
        libgcc-5-dev \
        libhwloc-dev \
        libibverbs-dev \
        libicu-dev \
        libltdl-dev \
        libncurses5-dev \
        libnuma-dev \
        libopenmpi-dev \
        libpython-dev \
        libpython2.7-dev \
        libreadline-dev \
        libreadline6-dev \
        libssl-dev \
        libstdc++-5-dev \
        libtinfo-dev \
        libtool \
        linux-libc-dev \
        m4 \
        make \
        manpages \
        manpages-dev \
        mpi-default-dev \
        python-dev \
        python2.7-dev \
        python3-dev \
    && \
    apt-get autoremove -y && \
    rm -rf \
        /var/lib/apt/lists/* \
        /tmp/* \
        /var/tmp/* \
        /var/cache/* \
        /usr/include \
        /usr/local/include

RUN useradd -s /bin/bash -m -d /var/lib/dpayd dpayd

RUN mkdir /var/cache/dpayd && \
    chown dpayd:dpayd -R /var/cache/dpayd

# add blockchain cache to image
#ADD $DPAYD_BLOCKCHAIN /var/cache/dpayd/blocks.tbz2

ENV HOME /var/lib/dpayd
RUN chown dpayd:dpayd -R /var/lib/dpayd

VOLUME ["/var/lib/dpayd"]

# rpc service:
EXPOSE 1776
# p2p service:
EXPOSE 6620

# add seednodes from documentation to image
ADD doc/seednodes.txt /etc/dpayd/seednodes.txt

# the following adds lots of logging info to stdout
ADD contrib/config-for-docker.ini /etc/dpayd/config.ini
ADD contrib/fullnode.config.ini /etc/dpayd/fullnode.config.ini
ADD contrib/config-for-broadcaster.ini /etc/dpayd/config-for-broadcaster.ini
ADD contrib/config-for-ahnode.ini /etc/dpayd/config-for-ahnode.ini

# add normal startup script that starts via sv
ADD contrib/dpayd.run /usr/local/bin/dpay-sv-run.sh
RUN chmod +x /usr/local/bin/dpay-sv-run.sh

# add nginx templates
ADD contrib/dpayd.nginx.conf /etc/nginx/dpayd.nginx.conf
ADD contrib/healthcheck.conf.template /etc/nginx/healthcheck.conf.template

# add PaaS startup script and service script
ADD contrib/startpaasdpayd.sh /usr/local/bin/startpaasdpayd.sh
ADD contrib/paas-sv-run.sh /usr/local/bin/paas-sv-run.sh
ADD contrib/sync-sv-run.sh /usr/local/bin/sync-sv-run.sh
ADD contrib/healthcheck.sh /usr/local/bin/healthcheck.sh
RUN chmod +x /usr/local/bin/startpaasdpayd.sh
RUN chmod +x /usr/local/bin/paas-sv-run.sh
RUN chmod +x /usr/local/bin/sync-sv-run.sh
RUN chmod +x /usr/local/bin/healthcheck.sh

# new entrypoint for all instances
# this enables exitting of the container when the writer node dies
# for PaaS mode (elasticbeanstalk, etc)
# AWS EB Docker requires a non-daemonized entrypoint
ADD contrib/dpaydentrypoint.sh /usr/local/bin/dpaydentrypoint.sh
RUN chmod +x /usr/local/bin/dpaydentrypoint.sh
CMD /usr/local/bin/dpaydentrypoint.sh
