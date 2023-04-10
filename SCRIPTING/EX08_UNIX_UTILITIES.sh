#!/bin/bash

options=("Create" "Head" "Tail" "Cut" "Paste" "Join" "Diff" "Exit")

PS3="Enter your option : "
select opt in ${options[@]}
do
  case $opt in 
         ${options[0]})
            read -p "Enter file name : " f
            touch $f 
            echo "Write something in file (Press Ctrl + D to stop writing)"
            cat >> $f ;;
        ${options[1]})
            read -p "Enter file name : " f
            head -10 $f ;;
         ${options[2]}) 
            read -p "Enter file name : " f
            tail -10 $f ;;
         ${options[3]})
            read -p "Enter file name : " f
            cut -c -2 $f ;;
         ${options[4]}) 
            read -p "Enter file name : " f1
            read -p "Enter file name : " f2
            paste $f1 $f2 ;;
         ${options[5]}) 
            read -p "Enter file name : " f1
            read -p "Enter file name : " f2
            read -p "Enter file name : " df
            cat $f1 $f2 > $df ;;
         ${options[6]}) 
            read -p "Enter file name : " f1
            read -p "Enter file name : " f2
            diff $f1 $f2;;      
         ${options[7]}) 
          echo "You are on Exit .."
          exit 0 ;;
    
    esac


done

