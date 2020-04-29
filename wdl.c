#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const char delimiter = ',';
const int SIZE = 30;
int res, fd0, fd1, g,w,x, y, rc;
struct termios options;
struct termios newtio;
char * debug_str = "test";
char my_str[1024];
char date_str[32];
char tmp_str1[64];
char tmp_str2[64];
char * str;
char * xyz;

struct data_struct {
char sample_date[30];
float wind_speed0 ;
float wind_gust0 ;
unsigned int pulse_count0;
float wind_speed1 ;
float wind_gust1 ;
unsigned int pulse_count1;
float wind_speed2 ;
float wind_gust2 ;
unsigned int pulse_count2;
float counter0;
float counter1;
float counter2;
int wind_dir;
float voltage;
float wind_vane_pot0;
float wind_vane_pot1;
float temp_sens;
float analogue4;
float analogue5;
float analogue6;
float analogue7;
} wdata;

// function protocypes

int set_port();
void write_rdl( ); 

//-------- These settings can easily be changed if required --------
     char *serial_port = "/dev/winddatalogger"; 
     char *path_to_rrd = "/usr/bin/rrdtool";

int main() {





fd0 = open("/dev/winddatalogger", O_RDONLY); // Open the serial port.
rc = set_port();

while(1){

	 res=read(fd0,my_str,1024);
        str=strstr(my_str,"BEDI");
                //printf("%s:\n",my_str);
       if(str) {
        	my_str[str-my_str]=0x00;  // add a null to the end to terminate the string
       
		printf("%s:\n",my_str);
        

		for (x=0;my_str[x]!=delimiter;x++ ){   // find  ',' first
		wdata.sample_date[x]=my_str[x]; } wdata.sample_date[x]='\0';


        	for (x=20, w=0;my_str[x]!=delimiter;w++,x++ ) tmp_str1[w]=my_str[x];
     		tmp_str2[w]='\0';
		wdata.wind_speed0 = atof(tmp_str1);
      		x++; 

        	for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
        	wdata.wind_gust0 = atof(tmp_str2);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.pulse_count0 = atoi(tmp_str2);
                x++; 
                  
 
                for ( w=0;my_str[x]!=delimiter;w++,x++ ) tmp_str1[w]=my_str[x];
                tmp_str2[w]='\0';
                wdata.wind_speed1 = atof(tmp_str1);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.wind_gust1 = atof(tmp_str2);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.pulse_count1 = atoi(tmp_str2);
                x++;

                for ( w=0;my_str[x]!=delimiter;w++,x++ ) tmp_str1[w]=my_str[x];
                tmp_str2[w]='\0';
                wdata.wind_speed2 = atof(tmp_str1);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.wind_gust2 = atof(tmp_str2);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.pulse_count2 = atoi(tmp_str2);
                x++;
        
                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.counter0 = atof(tmp_str2);
		x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.counter1 = atof(tmp_str2);
 		x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.counter2 = atof(tmp_str2);
		x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.wind_dir = atoi(tmp_str2);
		x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.voltage = atof(tmp_str2);
                x++;

                 for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.wind_vane_pot0 = atof(tmp_str2);
                wdata.wind_dir=(wdata.wind_vane_pot0 / 5*360);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.wind_vane_pot1 = atof(tmp_str2);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.temp_sens = atof(tmp_str2);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.analogue4 = atof(tmp_str2);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.analogue5 = atof(tmp_str2);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.analogue6 = atof(tmp_str2);
                x++;

                for ( g=0;my_str[x]!=delimiter;x++,g++ )   tmp_str2[g]=my_str[x];
                tmp_str2[g]='\0';
                wdata.analogue7 = atof(tmp_str2);
                x++;


                printf("Date: %s\n",wdata.sample_date);
                printf("Wind speed0: %3.1f \n", wdata.wind_speed0);
        	printf("Wind gust0:  %3.1f \n", wdata.wind_gust0);
                printf("Pulse count: %3i  \n", wdata.pulse_count0); 
                printf("Wind speed1: %3.1f \n", wdata.wind_speed1);
                printf("Wind gust1:  %3.1f \n", wdata.wind_gust1);
                printf("Pulse count: %3i  \n", wdata.pulse_count1);
                printf("Wind speed2: %3.1f \n", wdata.wind_speed2);
                printf("Wind gust2:  %3.1f \n", wdata.wind_gust2);
                printf("Pulse count: %3i  \n", wdata.pulse_count2);
                printf("Counter0:  %3.1f \n", wdata.counter0);
		printf("Counter1:  %3.1f \n", wdata.counter1);
		printf("Counter2:  %3.1f \n", wdata.counter2);
                printf("Wind Dir:  %3i   \n", wdata.wind_dir);
                printf("Voltage:  %3.1f   \n", wdata.voltage);
                printf("wind_vane_pot0:  %3.1f   \n", wdata.wind_vane_pot0);
                printf("wind_vane_pot1:  %3.1f   \n", wdata.wind_vane_pot1);
                printf("temp_sens:  %3.1f   \n", wdata.temp_sens);
                printf("analogue4:  %3.1f   \n", wdata.analogue4);
                printf("analogue5:  %3.1f   \n", wdata.analogue5);
                printf("analogue6:  %3.1f   \n", wdata.analogue6);
                printf("analogue7:  %3.1f   \n", wdata.analogue7);
        }
 write_rdl(); 

}

close(fd0);
//close(fd1);

return 1;
}


//--------------------------------------------------------------------
   int set_port() {
    memset(&newtio, 0, sizeof(newtio));
    tcgetattr(fd0, &newtio);
     newtio.c_cflag &= ~CRTSCTS;                 /* disable hardware flow control */
     newtio.c_cflag &= ~PARENB;                  /* no parity */
     newtio.c_cflag &= ~CSTOPB;                  /* one stop bit */
      newtio.c_cflag &= ~CSIZE;                   /* character size mask */
      newtio.c_cflag &= ~HUPCL;                   /* no hangup */
      newtio.c_cflag |= CS8 |CREAD ;                     /* 8 bits */
//    newtio.c_iflag |= IXON | IXOFF;
//    newtio.c_iflag |= IGNBRK | IGNPAR;          /* ignore BREAK condition on input & framing errors & parity errors */
       newtio.c_oflag = 0;                         /* set serial device input mode (non-canonical, no echo,...) */
//    newtio.c_oflag &= ~OPOST;                   /* enable output processing */
//    newtio.c_lflag = 0;
//    newtio.c_cc[VTIME]    = 1;                  /* timeout in 1/10 sec intervals */
//    newtio.c_cc[VMIN]     = 0;
    cfsetospeed (&newtio, B19200);
    cfsetispeed (&newtio, B19200);
    tcsetattr(fd0, TCSANOW, &newtio);
    return 0;
}


//--------------------------------------------------------------------
void write_rdl()
{
 char cmd[100];

    sprintf(cmd, "%s update weather_wind_speed.rrd --template wind_speed N:%2.1f",path_to_rrd,wdata.wind_speed0);
    system(cmd);
   
 sprintf(cmd, "%s update weather_wind_speed2.rrd --template wind_speed:wind_gust N:%2.1f:%2.1f",path_to_rrd,wdata.wind_speed0,wdata.wind_gust0);
    system(cmd);
      //  printf("\ns:%s",cmd);

    sprintf(cmd, "%s update weather_wind_direction.rrd --template wind_dir N:%03i",path_to_rrd,wdata.wind_dir);
    system(cmd);
       // printf("\nd:%s",cmd);

//        printf("string:  %s   \n",cmd);

}
