#!/bin/bash
set -e
sudo docker build --build-arg BUILD_STEP=1 -t=dpays/dpay:tests .
sudo docker run -v $WORKSPACE:/var/jenkins dpays/dpay:tests cp -r /var/cobertura /var/jenkins
# make docker cleanup after itself and delete all exited containers
sudo docker rm -v $(docker ps -a -q -f status=exited) || true