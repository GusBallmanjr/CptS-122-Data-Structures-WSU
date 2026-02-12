# PA 1 — Fitbit Data Analysis  
CptS 122 — Data Structures

## Overview
This project analyzes 24 hours of Fitbit activity data stored in a CSV file. Each record represents one minute of data and includes fields such as calories burned, distance walked, floors climbed, heart rate, steps taken, and sleep level.

The program filters the dataset to include only the target patient, removes duplicate entries, cleans missing fields, and stores the processed information in an array of FitbitData structs. It then computes summary statistics and outputs both the results and the cleaned dataset to a new CSV file.

## Features
+ Filters records to match the target patient  
+ Removes duplicate entries based on patient ID and minute  
+ Cleans missing or empty fields  
+ Stores valid data in an array of 1440 FitbitData structs  
+ Computes:
  + Total calories  
  + Total distance  
  + Total floors  
  + Total steps  
  + Average heart rate  
  + Maximum steps in a single minute  
  + Longest range of poor sleep  
+ Outputs results to Results.csv and prints them to the console  

## File Structure
