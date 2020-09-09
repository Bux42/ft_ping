#!/bin/sh
rebuild=1
arg_date=$(date -r .autobuild_args)
inc_date=$(date -r inc/header.h)

CheckRebuild() {
    cur_date_args=$(date -r .autobuild_args)
    if [ "$arg_date" != "$cur_date_args" ]
    then
        arg_date=$cur_date_args
        rebuild=$((1))
    fi

    cur_date_inc=$(date -r inc/header.h)
    if [ "$inc_date" != "$cur_date_inc" ]
    then
        inc_date=$cur_date_inc
        rebuild=$((1))
    fi
    

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
            sleep 2
        else
            echo "___________________________________"
            ./ft_ping $(cat .autobuild_args)
            rebuild=$((0))
        fi
        
    else
        CheckRebuild
    fi
sleep 0.5
done