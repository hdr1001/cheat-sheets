// *********************************************************************
//
// Basic C CGI coding example
//
// basics_html.c is a C cheat sheet for generating a CGI HTML page
// copyright 2012 Hans de Rooij
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along with this program; if not, write to the Free
// Software Foundation, Inc., 51 Franklin St, Boston, MA
// 20110-1301, USA.
//
//
// Compile using the GNU C compiler
//    gcc basics_html.c -o ~/public_html/cgi-bin/basics_html.cgi
//
// Compile using the GNU C++ compiler
//    g++ basics_html.c -o ~/public_html/cgi-bin/basics_html.cgi
//
// *********************************************************************

#include <stdio.h>


// *********************************************************************
//
// C code to dynamically generate a XHTML page
//
// *********************************************************************

int main(void)
{
   int i;

   printf("Content-Type:text/html; charset=utf-8\n\n");

   printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"\n");
   printf("   \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n\n");

   printf("<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
   printf("<head>\n");
   printf("   <title>CGI HTML basics</title>\n");
   printf("   <meta name=\"description\" content=\"XHTML CGI basics cheat sheet\" />\n");
   printf("   <meta name=\"author\" content=\"Hans de Rooij\" />\n");
   printf("   <meta name=\"keywords\" content=\"XHTML CGI basics cheat sheet template\" />\n");
   printf("   <meta name=\"version\" content=\"1.00\" />\n");
   printf("   <meta name=\"date\" content=\"2012-01-14 14:00:00 CEST\" />\n");
   printf("   <meta name=\"copyright\" content=\"&copy; 2012 Hans de Rooij\" />\n");
   printf("   <meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\" />\n");
   printf("   <link rel=\"stylesheet\" type=\"text/css\" href=\"../css/hdrcheat.css\" />\n");
   printf("   <style type=\"text/css\">\n");
   printf("   #code_results\n");
   printf("   {\n");
   printf("      width: 80%%;\n");
   printf("      padding: 10px 10px;\n");
   printf("      margin: 0 auto;\n");
   printf("      border-style: solid;\n");
   printf("      border-width: 1px;\n");
   printf("      border-color: #cccccc;\n");
   printf("      background-color: #ffffcc;\n");
   printf("      color: inherit;\n");
   printf("   }\n");
   printf("   #code_results pre\n");
   printf("   {\n");
   printf("      text-align: left;\n");
   printf("      white-space: pre;\n"); 
   printf("      font-family: monospace;\n"); 
   printf("      font-size: 1.2em;\n");
   printf("      padding: 5px;\n");
   printf("      margin: 0;\n");
   printf("   }\n");
   printf("   </style>\n");

   printf("</head>\n");
   printf("<body>\n");
   printf("   <div id=\"center_col\">\n\n");

   printf("   <div id=\"page_header\">\n");
   printf("   <div id=\"page_header_url\">\n");
   printf("   <h1>hdr.is-a-geek.com</h1>\n");
   printf("   </div> <!-- Close div page_header_url-->\n");
   printf("   <div id=\"page_header_quote\">\n");
   printf("   <p><strong>The moment you cheat for the sake of beauty, you know you're an\n");
   printf("      artist</strong><br />David Hockney</p>\n");
   printf("   </div> <!-- Close div page_header_quote-->\n");
   printf("   </div> <!-- Close div page_header-->\n\n");

   printf("   <div id=\"banner\">\n");
   printf("   <img src=\"../imgs/hdrbnr02.png\" alt=\"Site banner\" height=\"175\"\n");
   printf("      width=\"760\" />\n");
   printf("   </div> <!-- Close div banner-->\n\n");

   printf("   <div id=\"left_col\">\n");
   printf("   <div id=\"site_menu\">\n");
   printf("   <h3 class=\"hide\">Menu:</h3>\n");
   printf("   <ul>\n");
   printf("   <li><a href=\"http://hdr.is-a-geek.com\" title=\"Home\">Home</a></li>\n");
   printf("   <li><a href=\"http://cheat-sheets.googlecode.com/svn/trunk/html/basics.html\" \n");
   printf("      title=\"HTML cheat\">HTML cheat</a></li>\n");
   printf("   <li><a href=\"http://cheat-sheets.googlecode.com/svn/trunk/xhtml/basics.html\" \n");
   printf("      title=\"XHTML cheat\">XHTML cheat</a></li>\n");
   printf("   <li><a href=\"../css/hdrcheat.css\" title=\"CSS cheat\">CSS cheat</a></li>\n");
   printf("   <li><a href=\"http://cheat-sheets.googlecode.com/svn/trunk/c/basics.c\" \n");
   printf("      title=\"C basics\">C basics</a></li>\n");
   printf("   <li><a href=\"../c/intermediate.c\" title=\"C intermediate\">C intermediate</a>\n");
   printf("      </li>\n");
   printf("   <li><a href=\"http://cheat-sheets.googlecode.com/svn/trunk/c/basics_html.c\" \n");
   printf("      title=\"CGI basics\">CGI Basics</a></li>\n");
   printf("   <li><a href=\"../cpp/basics.cpp\" title=\"C++ basics\">C++ basics</a></li>\n");
   printf("   <li><a href=\"../vb/basics.bas\" title=\"VB basics\">VB basics</a></li>\n");
   printf("   </ul>\n");
   printf("   </div> <!-- Close div site_menu-->\n");
   printf("   <div id=\"announce\">\n");
   printf("   <h3>Latest news:</h3>\n");
   printf("   <p><strong>Jan 2012</strong><br />\n");
   printf("   No news</p>\n");
   printf("   <p><strong>Feb 2012</strong><br />\n");
   printf("   Still no news</p>\n");
   printf("   </div> <!-- Close div announce -->\n");
   printf("   </div> <!-- Close div left_col -->\n\n");

   printf("   <div id=\"right_col\">\n");
   printf("   <div id=\"add_info\">\n");
   printf("   <h3>Additional info</h3>\n");
   printf("   <p>\n");
   printf("      To view the source of this XHTML cheat sheet choose option (Page) Source\n");
   printf("      from your browser&#39;s View menu.\n");
   printf("   </p>\n");
   printf("   </div> <!-- Close div add_info -->\n");
   printf("   <div id=\"ext_menu\">\n");
   printf("   <h3>External links</h3>\n");
   printf("   <p>\n");
   printf("      - <a href=\"http://www.google.com\" title=\"Google\">Google</a><br />\n");
   printf("      - <a href=\"http://www.w3schools.com\" title=\"W3Schools\">W3Schools</a>\n");
   printf("         <br />\n");
   printf("      - <a href=\"http://validator.w3.org\" title=\"Validate HTML\">Validate HTML\n");
   printf("         </a><br />\n");
   printf("      - <a href=\"http://jigsaw.w3.org/css-validator/\" title=\"Validate css\">\n");
   printf("         Validate CSS</a><br />\n");
   printf("      - <a href=\"http://openwebdesign.org/design/2199/andreas01/\"\n");
   printf("         title=\"Original design, Andreas01\">Original design</a>\n");
   printf("   </p>\n");
   printf("   </div> <!-- Close div ext_menu -->\n");
   printf("   </div> <!-- Close div right_col -->\n\n");

   printf("   <div id=\"content\">\n");
   printf("   <h1 style=\"margin-top:0\">Execute functions from basics.c</h1>\n");
   printf("   <p>Please select a function from the dropdown below and the corresponding code\n");
   printf("      in <a href=\"http://cheat-sheets.googlecode.com/svn/trunk/c/basics.c\"\n");
   printf("      title=\"C Basics\">basics.c</a> will be executed. The output of the code\n");
   printf("      will be shown in the section of this page labelled code results.</p>\n\n");

   printf("   <form method=\"post\" enctype=\"application/x-www-form-urlencoded\"\n");
   printf("      action=\"mailto:HansDeRooij@Hotmail.com\">\n\n");
   printf("   <fieldset>\n");
   printf("   <legend>Select a function</legend>\n\n");
   printf("   <table>\n\n");
   printf("   <col class=\"FormLeftCol\" />\n");
   printf("   <col class=\"FormMiddleCol\" />\n");
   printf("   <col class=\"FormRightCol\" />\n\n");
   printf("   <tr><td colspan=\"3\" style=\"height:8px\"></td></tr>\n");
   printf("   <tr>\n");
   printf("      <td><label for=\"ddmFuncChoice\" class=\"ll\">Function choice</label></td>\n");
   printf("      <td colspan=\"2\">\n");
   printf("         <select name=\"ddmFuncChoice\" id=\"ddmFuncChoice\">\n");
   for(i = 1; i <= 30; i++)
   {
      if(i == 1)
      {
         printf("            ");
         printf("<option value=\"%d\" selected=\"selected\">Function %d</option>\n", i, i);
      }
      else
      {
         printf("            ");
         printf("<option value=\"%d\">Function %d</option>\n", i, i);
      }
   }
   printf("         </select>\n");
   printf("      </td>\n");
   printf("   </tr>\n\n");
   printf("   <tr><td colspan=\"3\" style=\"height:8px\"></td></tr>\n");
   printf("   <tr>\n");
   printf("      <td></td>\n");
   printf("      <td colspan=\"2\">\n");
   printf("         <input type=\"submit\" class=\"SubmOrRe\" value=\"Submit\"\n");
   printf("            accesskey=\"s\" />\n");
   printf("         <input type=\"reset\" class=\"SubmOrRe\" value=\"Reset\"\n");
   printf("            accesskey=\"r\" />\n");
   printf("      </td>\n");
   printf("   </tr>\n\n");
   printf("   </table>\n");
   printf("   </fieldset>\n");
   printf("   </form>\n\n");

   printf("   <h2>Code results</h2>\n");
   printf("   <div id=\"code_results\">\n");
   printf("   <pre>Code results here</pre>\n");
   printf("   </div> <!-- Clode div code_results -->\n");
   printf("   </div> <!-- Close div content -->\n\n");

   printf("   <hr id=\"below_content\" />\n\n");

   printf("   <div id=\"contact_info\">\n");
   printf("   <address>\n");
   printf("      Comments to <a href=\"mailto:HansDeRooij@Hotmail.com\" title=\"author\">\n");
   printf("      Hans de Rooij</a>\n");
   printf("   </address>\n");
   printf("   </div> <!-- Close div contact_info -->\n\n");

   printf("   <div id=\"tech_dedication\">\n");
   printf("   <p>\n");
   printf("      <img src=\"../imgs/BubbleBoy.jpg\" alt=\"BubbleBoy\" />\n");
   printf("      <img src=\"../imgs/UbuntuServer.png\" alt=\"Ubuntu Server\" />\n");
   printf("      <img src=\"../imgs/ApacheLogo.png\" alt=\"Apache Server\" />\n");
   printf("      <a href=\"http://validator.w3.org/check?uri=referer\">\n");
   printf("         <img src=\"http://www.w3.org/Icons/valid-xhtml10.gif\"\n");
   printf("              alt=\"Valid XHTML 1.0 Strict\" />\n");
   printf("      </a>\n");
   printf("      <a href=\"http://jigsaw.w3.org/css-validator/check/referer\">\n");
   printf("         <img src=\"http://jigsaw.w3.org/css-validator/images/vcss\"\n");
   printf("              alt=\"Valid CSS\" />\n");
   printf("      </a>\n");
   printf("   </p>\n");
   printf("   </div> <!-- Close div tech_dedication -->\n\n");

   printf("   <div id=\"legal\">\n");
   printf("   <p>basics_html.cgi is a CGI eXtensible HyperText Markup Language cheat sheet</p>\n");
   printf("   <p>&copy; 2012 Hans de Rooij &#124; Original design <a \n");
   printf("      href=\"http://andreasviklund.com\" title=\"Andreas Viklund\">\n");
   printf("      Andreas Viklund</a></p>\n");
   printf("   <p>This program is free software; you can redistribute it and/or modify it\n");
   printf("      under the terms of the GNU General Public License as published by the\n");
   printf("      Free Software Foundation; either version 2 of the License, or (at your\n");
   printf("      option) any later version.\n");
   printf("   </p>\n");
   printf("   <p>This program is distributed in the hope that it will be useful, but\n");
   printf("      WITHOUT ANY WARRANTY; without even the implied warranty of\n");
   printf("      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General\n");
   printf("      Public License for more details.\n");
   printf("   </p>\n");
   printf("   <p>You should have received a copy of the <a \n");
   printf("      href=\"http://www.gnu.org/licenses/gpl.html\" title=\"GNU GPL\">GNU General\n");
   printf("      Public License</a> along with this program; if not, write to the Free\n");
   printf("      Software Foundation, Inc., 51 Franklin St, Boston, MA 20110-1301, USA.\n");
   printf("   </p>\n");
   printf("   </div> <!-- Close div legal -->\n");

   printf("   </div> <!-- Close div center_col -->\n");
   printf("</body>");
   printf("</html>\n");
}

