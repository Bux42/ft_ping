#!/bin/sh
rebuild=1

CheckRebuild () {
    folders=$(ls src/)
    for folder in $folders
    do
        subfolders=$(ls src/$folder)
        for sourcefile in $subfolders
        do
            objfile="${sourcefile%?}o"
            if [ "src/$folder/$sourcefile" -nt "objs/$folder/$objfile" ]
            then
                rebuild=$((1))
            fi
        done
    done
}

while true
do
    if [ $rebuild -eq 1 ]
    then
        make re
        if [ $? -eq 2 ]
        then
            sleep 1
        else
            echo "___________________________________"
            ./ft_ping 127.0.0.1
            rebuild=$((0))
        fi
        
    else
        CheckRebuild
    fi
sleep 0.5
done