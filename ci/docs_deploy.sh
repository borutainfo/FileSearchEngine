#!/bin/sh
set -e
echo 'Docs deploy starts...'

cd ${TRAVIS_BUILD_DIR}/../

mkdir doc && cd doc
git clone -b gh-pages https://${GITHUB_TOKEN}@${GITHUB_REF}

cd ${TRAVIS_BUILD_DIR}/build/doc_doxygen/

if [ -d "html" ] && [ -f "html/index.html" ]; then
    echo 'Uploading documentation to the gh-pages branch...'

    yes | cp -rf ./html/* ${TRAVIS_BUILD_DIR}/../doc/${GITHUB_NAME}
    cd ${TRAVIS_BUILD_DIR}/../doc/${GITHUB_NAME}

    git config --global push.default simple
    git config user.name "Travis CI"
    git config user.email "travis@travis-ci.com"

    git add --all
    git commit -m "Deploy doc to GitHub Pages, Travis CI build: ${TRAVIS_BUILD_NUMBER}" -m "Commit: ${TRAVIS_COMMIT}"

    git push --force "https://${GITHUB_TOKEN}@${GITHUB_REF}" > /dev/null 2>&1

    echo 'Documentation successfully uploaded!'
else
    echo '' >&2
    echo 'Error: No documentation files have been found!' >&2
    exit 1
fi
