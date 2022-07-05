ArrayList=""

for lineNumber in `cat $1| echo $(( 0+ $(wc -l) )) |xargs seq 0`; do

    ## Parse and create Arrays
    if [[ $lineNumber == 0 ]];
      then
      unset $ArrayList
      for j in `head -1 $1|cut -d "," -f 2-|sed 's/,/ /g'`; do 
          declare -A $j;
          ArrayList=${ArrayList}" "$j

      done
      continue
    fi

    index=1
    lNum=$(( 1+ $lineNumber ))
    name=`sed "${lNum}q;d" $1|cut -d "," -f 1`

    ## Parse and add values from line to dictionary 
    for k in `sed "${lNum}q;d" $1 |cut -d "," -f 2-|sed 's/,/ /g'`; do
      command=$(echo $ArrayList|cut -d " " -f $index)[$name]="$k"
      eval "$command"
      #echo $command
      index=$(( index+1 ));
    done
done