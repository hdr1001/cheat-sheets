#include <stdio.h>

int main(void)
{
   printf("Content-Type:text/xml;charset=utf-8\n\n");

   printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"");
   printf("\"   http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">");

   printf("<html xmlns=\"http://www.w3.org/1999/xhtml\">");
   printf("<head>");
   printf("</head>");
   printf("<body>");
   printf("<p>Hello cgi world</p>");
   printf("</body>");
   printf("</html>");
}

