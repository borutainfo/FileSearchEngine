FileSearchEngine
---
[![Build Status](https://travis-ci.com/borutainfo/FileSearchEngine.svg?token=zpox7R7TPwtc4HzNgepa&branch=master)](https://travis-ci.com/borutainfo/FileSearchEngine)
[![Documentation](https://img.shields.io/badge/doxygen-docs-blue.svg)](https://borutainfo.github.io/FileSearchEngine)

A simple search engine for texts in files.

## About application

Application has been created as part of a student project in the subject Advanced C++ at the Warsaw University of Technology by [Sebastian Boruta](https://boruta.info/).

## Available commands

```bash
about
```
Show information about the project and the author.


```
add $filename1 [$filename2 ...]
```
Add a file to the collection in which you will search for data. You can add one file or several at a time.


```
delete $filename1 [$filename2 ...]
```
Delete file from collection in which you will search for data. You can delete one file or several at a time.


```
exit
```
Close the application.


```
help
```
Get information about how to use this application.


```
search $searchQuery
```
Search for text in files added to the collection using the given expression. You can use brackets `(`, `)`, and following operators `AND`, `OR`, `NOT`. The size of the characters matters - for operators, you must use capital letters. The operator must be separated by a space from the search text.

You can use any characters. If you use spaces between two words the engine will search for the entire expression (including spaces). If you want to search for a bracket, you must precede it with a slash.

Some examples - good:
    ```
    search Sebastian AND Boruta
    search Sebastian OR Boruta AND NOT Kowalski
    search (Sebastian Boruta OR Mickiewicz) AND NOT Kowalski
    search (NOT (Sebastian OR Boruta) AND Kowalski) OR Nowak
    ```

BAD (not working properly):
    ```
    search SebastianANDBoruta
    search SebastianOR Boruta AND NOTKowalski
    search Sebastian OR Boruta) AND NOT Kowalski
    search (NOT (Sebastian OR Boruta) AND Kowalski)OR((Nowak
    ```

## Documentation

See [Doxygen documentation](https://borutainfo.github.io/FileSearchEngine) deploy automatically by `travis-ci` to `gh-pages` branch.
