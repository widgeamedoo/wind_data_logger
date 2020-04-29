# wind_data_logger
Wind data logger interface for raspberry pi to publish wind data on a website using Tobi Oeticker graphs.
The create_rrd_graphs.sh script generate the graph inages, run this from cron.
This requires an RS232 to USB interface to conect to a wind data logger.
Provides daily, weekly, monthly, yearly outputs.
Need a bit of work on the graph outptu - particularly on the Yearly graph.
checkstart is a program to check if the app is runnning and restart if necessaey, this lives in cron
Modify this file: /etc/udev/rules.d/50-usbserial.rules and add: 
SUBSYSTEMS=="usb",  ATTRS{product}=="USB2.0-Ser!", KERNELS=="1-1.2" SYMLINK+="winddatalogger", ACTION=="add", MODE="0666"
