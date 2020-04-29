#! /bin/sh
#################################################################
#     Title: put_graphs.sh                                      #
#     Script to ftp weather log files                           #
#                                                               #
#   put_graphs.sh   July 13                                     #
#   Author: Alan Barrow                                         #
#   Version: 1.0                                                #
#################################################################
FROM_DIR="tmp"
DEST_DIR="/www/images/"
FTPLOG=/home/pi/graphs_ftp.log
dest=chelseayachtclub.com.au
USER='chels'




############################################################
# Get all the files from the directory on the remote machine
############################################################
#
sftp  $USER@$dest  <<-end
quote USER $USER 
mput /tmp/wind_direction_daily.png
mput /tmp/wind_daily.png
bye
end
