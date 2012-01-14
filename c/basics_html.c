#include <stdio.h>

int main(void)
{
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
   printf("   <li><a href=\"http://cheat-sheets.googlecode.com/svn/trunk/html/basics.html\" ");
   printf("      title=\"HTML cheat\">HTML cheat</a></li>\n");
   printf("   <li><a href=\"http://cheat-sheets.googlecode.com/svn/trunk/xhtml/basics.html\" ");
   printf("      title=\"XHTML cheat\">XHTML cheat</a></li>\n");
   printf("   <li><a href=\"../css/hdrcheat.css\" title=\"CSS cheat\">CSS cheat</a></li>\n");
   printf("   <li><a href=\"http://cheat-sheets.googlecode.com/svn/trunk/c/basics.c\" ");
   printf("      title=\"C basics\">C basics</a></li>\n");
   printf("   <li><a href=\"../c/intermediate.c\" title=\"C intermediate\">C intermediate</a>\n");
   printf("      </li>\n");
   printf("   <li><a href=\"http://cheat-sheets.googlecode.com/svn/trunk/c/basics_html.c\" ");
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
   printf("   <h1 style=\"margin-top:0\">Document header (level 1)</h1>\n");
   printf("   </div> <!-- Close div content -->\n\n");

   printf("   <hr id=\"below_content\" />\n");

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
   printf("   <p>basics_html.cgi is an eXtensible HyperText Markup Language cheat sheet</p>\n");
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

   printf("   </div> <!-- Close div center_col-->\n");
   printf("</body>");
   printf("</html>\n");
}

