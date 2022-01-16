#!/bin/base
echo "[step 1 start] set default github config"
git config --local user.name "debuginn" && git config --local user.email "debuginn@icloud.com"
echo "[step 1 end]   set default github config"

echo "[step 2 start] git pull remote code"
git pull origin master
echo "[step 2 end]   git pull remote code"

echo "[step 3 start] git pull local code"
git add .
if [ ! -n "$1" ]; then
  echo "please input commit desc"
  exit 1
fi
git commit -m "$1"
git push origin master
echo "[step 3 end]   git pull local code"