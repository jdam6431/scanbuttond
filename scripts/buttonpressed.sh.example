#!/bin/sh

# This script is started by scanbuttond whenever a scanner button has been pressed.
# Scanbuttond passes the following parameters to us:
# $1 ... the button number
# $2 ... the scanner's SANE device name, which comes in handy if there are two or 
#        more scanners. In this case we can pass the device name to SANE programs 
#        like scanimage.

TMPFILE="/tmp/scan.tiff"
LOCKFILE="/tmp/copy.lock"

case $1 in
	1)
		echo "button 1 has been pressed on $2"
		
		# This example turns your scanner+printer into a photocopier.
		# Fine-tuned for the Epson Perfection 2400, the HP LaserJet 1200 and
		# ISO A4 paper size so that the scanned document matches the printer
		# output as closely as possible.
		# The festival speech synthesizer is used to inform the user about
		# the progress of the operation.
		#
		#
		# if [ -f $LOCKFILE ]; then
		#   echo "Error: Another scanning operation is currently in progress" | festival --tts
		#   exit
		# fi
		# touch $LOCKFILE
		# rm -f $TMPFILE
		# echo "Copying" | festival --tts
		# scanimage --device-name $2 --format tiff --mode Gray --quick-format A4 \
		# --resolution 300 --sharpness 0 --brightness -3 \
		# --gamma-correction "High contrast printing" > $TMPFILE
		# if [ $? != 0 ]; then
		# 	echo "Scanning failed" | festival --tts
		# 	rm $LOCKFILE
		# 	exit
		# fi
		# echo "Submitting print job" | festival --tts
		# tiff2ps -z -w 8.27 -h 11.69 $TMPFILE | lpr
		# if [ $? != 0 ]; then
		# 	echo "Printing failed" | festival --tts
		# 	rm $LOCKFILE
		# 	exit
		# fi
		# echo "The print job has been submitted" | festival --tts
		# rm -f $LOCKFILE
		#
		;;
	2)
		echo "button 2 has been pressed on $2"
		;;
	3)
		echo "button 3 has been pressed on $2"
		;;
	4)
		echo "button 4 has been pressed on $2"
		;;
esac

