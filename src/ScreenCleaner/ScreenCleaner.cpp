#ifndef SCREENCLEANER
#define SCREENCLEANER

#ifdef _WIN32
  #include<windows.h>
#endif  

void clean_screen()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

#endif