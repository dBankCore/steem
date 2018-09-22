#/bin/bash
curl --silent -XPOST -H "Authorization: token $GITHUB_SECRET" https://api.github.comrepos/dpays/dpay/statuses/$(git rev-parse HEAD) -d "{
  \"state\": \"success\",
  \"target_url\": \"${BUILD_URL}\",
  \"description\": \"Jenkins-CI reports build succeeded!!\",
  \"context\": \"jenkins-ci-dpay\"
}"
rm -rf $WORKSPACE/*
# make docker cleanup after itself and delete all exited containers
sudo docker rm -v $(docker ps -a -q -f status=exited) || true
