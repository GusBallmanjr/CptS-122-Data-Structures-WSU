# PA 2 & 3 - Digital Music Manager  
CptS 122 — Data Structures

## Overview
This project implements a text‑based Digital Music Manager (DMM) that loads, stores, displays, edits, rates, and plays songs from a playlist stored in a CSV file. The playlist is represented as a dynamic doubly linked list, where each node contains a `Record` describing a single song.

The program provides a menu‑driven interface that allows the user to interact with the playlist and perform basic music‑library operations.

## Features
+ **Load** records from musicPlayList.csv into a doubly linked list  
+ **Store** the current playlist back into the CSV file  
+ **Display** all records or all records by a specific artist  
+ **Edit** a selected record’s attributes  
+ **Rate** a song with a value from 1–5  
+ **Play** songs sequentially from a chosen starting point  
+ **Exit** and save the playlist  

## Data Structures
### Duration
Represents the length of a song.
+ Minutes (int)  
+ Seconds (int)

### `Record`
Represents a single song entry.
+ Artist  
+ Album title  
+ Song title  
+ Genre  
+ Duration (minutes, seconds)  
+ Times played  
+ Rating (1–5)

### Node (Doubly Linked List)
+ Record data  
+ Pointer to next node  
+ Pointer to previous node  
