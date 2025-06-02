vi question_3.sh

	echo "Enter String_1 : "
	read String_1 
	echo "Enter String_2 : "
	read String_2 
	
	len1=${#String_1}
	len2=${#String_2}
	
	if [ $len1 -gt $len2 ]; then
		echo $String_1 " is larger than " $String_2
	elif [ $len2 -gt $len1 ]; then
		echo $String_2 " is larger than " $String_1
	else
		echo "Both strings are equal of length"
	fi

chmod 777 question_3.sh

./question_3.sh


