#directory="./samples/"
directory="./true_samples/samples_lex_and_syntax/"
num=0
for file in `ls $directory`
do
  if ! [ -d $directory/$file ]
  then
    echo testing $num: $file...
    ./build/compiler $directory/$file
    RETURN=$?
    echo ------------------------------------------
    if   [ $RETURN != 0 ] && [ "${file:3:5}" == "false" ]
    then
      echo "pass."
    elif [ $RETURN == 0 ] && [ "${file:3:4}" == "true" ]
    then
      echo "pass."
    else
      echo "not pass!" 
    fi
    ((num=num+1))
  fi
  echo -e "\n"
  echo -e "\n"
  echo -e "\n"
done
