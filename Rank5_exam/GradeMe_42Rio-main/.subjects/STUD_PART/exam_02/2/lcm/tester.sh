FILE='lcm.c'
ASSIGN='lcm'

bash .system/auto_correc_main.sh $FILE $ASSIGN "1" "2"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "3" "8"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "-1" "2932"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "-13" "2932"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "0" "2932"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi




touch .system/grading/passed;
