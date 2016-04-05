/*
 * Zoe Wilson
 * April 5, 2016
 * Sentence Filter
 */

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

/*
 * Changes all words to lowercase.
 * If there is a period the following word is Capitalized.
 * @returns boolean.
 */
bool process_line(std::ofstream &out_file, char *cp, bool just_seen_period) {
   while(*cp != 0) {
      char c = *cp++;

      // Check to see if it's an alphabet letter
      if(isalpha(c)) {
          c = tolower(c);
           
          // If period was just seen then next word is uppercase.
          if(just_seen_period) {
              c = toupper(c);

              // Reset to no period.
              just_seen_period = false;
          }
      } else if (c == '.') {
          just_seen_period = true;
          out_file.put(c);
      }
   } 
   out_file.put('\n');
   return just_seen_period;
}
      
/*
 * Error opening file.
 * exits.
 */
void open_error(std::string filename) {
    std::cout << "Error opening " << filename << std::endl;
    exit(EXIT_FAILURE);
}

int main() {
    const int MAX = 1001;

    // Recent read line from input.
    char input_line[MAX];

    // Input file name.
    std::string in_name;

    // Output file name.
    std::string out_name;
    
    // Input file object.
    std::ifstream in_file;

    // Output file object.
    std::ofstream out_file;

    // True if we have not seen a latter since the last period. 
    bool just_seen_period;

    // Get the input file name.
    std::cout << "Enter the input file name: " << std::endl;
    std::getline(std::cin, in_name);

    // Get the output file name.
    std::cout << "Enter the output file name: " << std::endl;
    std::getline(std::cin, out_name);

    // Open input file.
    in_file.open(in_name.c_str());
    if(in_file.fail()) {
        open_error(in_name);
    }

    // Open output file.
    out_file.open(out_name.c_str());
    if(out_file.fail()) {
        open_error(out_name);
    }

    // Initially we have just a seen period (pretend).
    just_seen_period = true;
    in_file.getline(input_line, MAX, '\n');

    // Calls function.
    while(!in_file.fail()) {
        just_seen_period = process_line(out_file, input_line, just_seen_period);
        in_file.getline(input_line, MAX,'\n');
    }

    // Close files. 
    in_file.close();
    out_file.close();

    return 0;
}
