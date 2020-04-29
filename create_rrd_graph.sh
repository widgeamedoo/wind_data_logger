cd /home/pi/weather
#TZ='Australia/Melbourne'; export TZ
/usr/bin/rrdtool graph /tmp/wind_speed_daily.png \
-w 960 -h 185 -a PNG \
--start -86400 --end now \
--vertical-label "Knots" \
--font DEFAULT:7: \
--title "Chelsea Yacht Club Wind Speed " \
--lower-limit 0 \
--x-grid MINUTE:30:MINUTE:30:MINUTE:60:0:%H:%M \
--alt-y-grid --rigid \
DEF:wind_speed=weather_wind_speed.rrd:wind_speed:MAX \
LINE1:wind_speed#0000FF:"Wind speed" \
GPRINT:wind_speed:LAST:"Cur\: %5.1lf" \
GPRINT:wind_speed:AVERAGE:"Avg\: %5.1lf" \
GPRINT:wind_speed:MAX:"Max\: %5.1lf" \
GPRINT:wind_speed:MIN:"Min\: %5.1lf\t\t\t" \
HRULE:10#0066FF \
HRULE:20#FA0404 \
HRULE:30#D104FA \
HRULE:40#000000 \
HRULE:50#000000


/usr/bin/rrdtool graph /tmp/wind_speed_daily2.png \
-w 960 -h 185 -a PNG \
--start -86400 --end now \
--vertical-label "Knots" \
--font DEFAULT:7: \
--title "Chelsea Yacht Club Wind Speed Including Gusts" \
--lower-limit 0 \
--x-grid MINUTE:30:MINUTE:30:MINUTE:60:0:%H:%M \
--alt-y-grid --rigid \
DEF:wind_gust=weather_wind_speed2.rrd:wind_gust:MAX \
LINE1:wind_gust#00FF00:"Wind gust" \
GPRINT:wind_gust:LAST:"Cur\: %5.1lf" \
GPRINT:wind_gust:AVERAGE:"Avg\: %5.1lf" \
GPRINT:wind_gust:MAX:"Max\: %5.1lf" \
GPRINT:wind_gust:MIN:"Min\: %5.1lf\t\t\t" \
DEF:wind_speed=weather_wind_speed2.rrd:wind_speed:MAX \
LINE2:wind_speed#0000FF:"Wind speed " \
GPRINT:wind_speed:LAST:"Cur\: %5.1lf" \
GPRINT:wind_speed:AVERAGE:"Avg\: %5.1lf" \
GPRINT:wind_speed:MAX:"Max\: %5.1lf" \
GPRINT:wind_speed:MIN:"Min\: %5.1lf\t\t\t" \
HRULE:10#0066FF \
HRULE:20#FA0404 \
HRULE:30#D104FA \
HRULE:40#000000 \
HRULE:50#000000

/usr/bin/rrdtool graph /tmp/wind_speed_hour.png \
-w 960 -h 185 -a PNG \
--start -4800 --end now \
--vertical-label "Knots" \
--font DEFAULT:7: \
--title "Chelsea Yacht Club Wind Speed Last - Last hour" \
--lower-limit 0 \
--x-grid MINUTE:5:HOUR:1:MINUTE:5:0:%H:%M \
--alt-y-grid --rigid \
DEF:wind_speed=weather_wind_speed.rrd:wind_speed:AVERAGE \
LINE1:wind_speed#0000FF:"Wind speed " \
GPRINT:wind_speed:LAST:"Cur\: %5.1lf" \
GPRINT:wind_speed:AVERAGE:"Avg\: %5.1lf" \
GPRINT:wind_speed:MAX:"Max\: %5.1lf" \
GPRINT:wind_speed:MIN:"Min\: %5.1lf\t\t\t" \
HRULE:10#0066FF \
HRULE:20#FA0404 \
HRULE:30#D104FA \
HRULE:40#000000 \
HRULE:50#000000


/usr/bin/rrdtool graph /tmp/wind_direction_daily.png \
-w 960 -h 185 -a PNG \
--start -86400 --end now \
--vertical-label "Deg Magnetic" \
--font DEFAULT:7: \
--title "Chelsea Yacht Club Wind direction" \
--lower-limit 0 \
--x-grid MINUTE:30:MINUTE:30:MINUTE:60:0:%H:%M \
--alt-y-grid --rigid \
DEF:wind_dir=weather_wind_direction.rrd:wind_dir:AVERAGE \
LINE1:wind_dir#0000FF:"Wind direction" \
GPRINT:wind_dir:LAST:"Cur\: %5.1lf" \
GPRINT:wind_dir:AVERAGE:"Avg\: %5.1lf" \
GPRINT:wind_dir:MAX:"Max\: %5.1lf" \
GPRINT:wind_dir:MIN:"Min\: %5.1lf\t\t\t" \
HRULE:90#99FF00:"East" \
HRULE:180#CC66CC:"South" \
HRULE:270#FF9933:"West" \
HRULE:0#009933:"North" \
HRULE:365#009933 

/usr/bin/rrdtool graph /tmp/wind_speed_weekly.png \
-w 960 -h 185 -a PNG \
--start -604800 --end now \
--vertical-label "Knots" \
--font DEFAULT:7: \
--title "Chelsea Yc Wind Speed - last week" \
--lower-limit 0 \
--x-grid MINUTE:120:MINUTE:720:MINUTE:1440:0:%a:%d:%m:%Y \
DEF:wind_speed=weather_wind_speed.rrd:wind_speed:MAX \
LINE2:wind_speed#0000FF:"Knots" \
GPRINT:wind_speed:LAST:"Cur\: %5.1lf" \
GPRINT:wind_speed:AVERAGE:"Avg\: %5.1lf" \
GPRINT:wind_speed:MAX:"Max\: %5.1lf" \
GPRINT:wind_speed:MIN:"Min\: %5.1lf\t\t\t" \
HRULE:10#0066FF \
HRULE:20#FA0404 \
HRULE:30#D104FA \
HRULE:40#000000 \
HRULE:50#000000

/usr/bin/rrdtool graph /tmp/wind_speed_monthly.png \
-w 960 -h 185 -a PNG \
--start -2592000 --end now \
--vertical-label "Knots" \
--font DEFAULT:7: \
--title "Chelsea Yc Wind Speed - last month" \
--lower-limit 0 \
--x-grid MINUTE:1440:MINUTE:720:MINUTE:1440:0:%d \
DEF:wind_speed=weather_wind_speed.rrd:wind_speed:MAX \
LINE2:wind_speed#0000FF:"Knots" \
GPRINT:wind_speed:LAST:"Cur\: %5.1lf" \
GPRINT:wind_speed:AVERAGE:"Avg\: %5.1lf" \
GPRINT:wind_speed:MAX:"Max\: %5.1lf" \
GPRINT:wind_speed:MIN:"Min\: %5.1lf\t\t\t" \
HRULE:10#0066FF \
HRULE:20#FA0404 \
HRULE:30#D104FA \
HRULE:40#000000 \
HRULE:50#000000

/usr/bin/rrdtool graph /tmp/wind_speed_yearly.png \
-w 960 -h 185 -a PNG \
--start -31104000 --end now \
--vertical-label "Knots" \
--font DEFAULT:7: \
--title "Chelsea Yc Wind Speed - maximums over last year" \
--lower-limit 0 \
--x-grid MINUTE:43200:MINUTE:10080:MINUTE:43200:0:%b-%y \
DEF:wind_speed=weather_wind_speed.rrd:wind_speed:MAX \
LINE2:wind_speed#0000FF:"Knots" \
GPRINT:wind_speed:LAST:"Cur\: %5.1lf" \
GPRINT:wind_speed:AVERAGE:"Avg\: %5.1lf" \
GPRINT:wind_speed:MAX:"Max\: %5.1lf" \
GPRINT:wind_speed:MIN:"Min\: %5.1lf\t\t\t" \
HRULE:10#0066FF \
HRULE:20#FA0404 \
HRULE:30#D104FA \
HRULE:40#000000 \
HRULE:50#000000
