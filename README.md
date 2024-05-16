# AVL Tree Search Engine

This project implements a simple search engine that allows users to search for URLs based on keywords. It utilizes a AVL Tree data structure to efficiently store and retrieve the data.
The tree automatically balances the node on left and right side to minimize the time complexity as compared to normal Binary search tree(BST).

## Overview

Search engines have become an integral part of our lives, and this project aims to provide a basic implementation of a search engine using a console-based interface.

## Input Format

The program reads data from a file with the following format:

- Each pair of lines represents a data item.
- The first line contains an ID and a URL.
- The second line contains a set of keywords (space-separated).
- Blank lines separate pairs of lines.
- Two consecutive blank lines indicate the end of the file.

## Program

The program functions as follows:

1. Asks the user for a filename.
2. Read data from the file and construct a BST.
3. Present a menu to the user.
4. Allow the user to enter keywords for searching.
5. Output the list of URLs that match the keywords.

## Setting up the Interface

 Setting up a simple console-based interface. Although it doesn't provide proper functionality, it is able to read from a file, ask the user for keywords to search, and handle invalid input.

## Implementation of the Search Engine

Implementing the search engine using a Binary Search Tree (BST). Each node of the BST stores a keyword along with an associated list of URLs. Implemented insert and search operations for keywords.

## Usage

1. Run the program.
2. Enter the filename containing data.
3. Enter keywords to search.
4. View the list of URLs matching the keywords.

## Language
 C++
