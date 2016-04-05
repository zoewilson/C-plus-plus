/*
 * Zoe Wilson
 * March 5, 2016
 * Population problem #3
 */


#include <iostream>


/* Population */
class Population {
    
  private:
    
    /* The population total */
    float population;
    
    /* The birth rate */
    float birth_rate;
    
    /* The death rate */
    float death_rate;

  public:
   
    /* Constructor */
    Population(float _p, float _br, float _dr) 
        : population(_p), birth_rate(_br), death_rate(_dr) {}
        
    /* Destructor */
    Population(const Population& orig) 
        : population(orig.population), birth_rate(orig.birth_rate), death_rate(orig.death_rate) {}
    
    /* Copy constructor */
    ~Population() {}
      
    /* Sets the population */
    void set_population(float new_pop) { 
        population = new_pop;
    }
    
    /* Gets the population */
    float get_population() const { 
        return population;
    }
    
    /* Gets the birth rate */
    float get_birth_rate() const { 
        return birth_rate;
    }
    
    /* Gets the death rate */
    float get_death_rate() const { 
        return death_rate; 
    }
    
};


/* Operator overload for << */
std::ostream& operator << (std::ostream& out, Population& population) {
    population.set_population(population.get_population() 
                              + (population.get_population() * (population.get_birth_rate() / 100))
                              + (population.get_population() * (population.get_death_rate() / 100)));
   
   // Convert to an integer by truncating float: cannot have a fraction of a person
   int new_population = population.get_population(); 
   out << new_population << std::endl;
   
   return out;
}


/* Main */
int main() {
    float population = 0;
    float birth_rate = 0;
    float death_rate = 0;
    int years = 0;

    while (true) {
        std::cout << "Enter the beginning population: ";
        std::cin >> population;
      
        // Population must be greater than 2
        if (population >= 2) {
            break;
        }
        std::cout << "Please enter the beginning value of your population (greater than 2): ";
    }

    std::cout << "Enter the birth rate (%): ";
    std::cin >> birth_rate;

    std::cout << "Enter the death rate (%): ";
    std::cin >> death_rate;

    if (death_rate > 0) {
        death_rate *= -1;
    }

    // Creating population object
    Population myPopulation(population, birth_rate, death_rate);

    std::cout << "Enter how many years you would like to pass: ";
    std::cin >> years;

    // Printing Results
    for (int i = 0; i < years; ++i) {
        std::cout << "----------------" << std::endl;
        std::cout << "Year: " << i + 1 << std::endl;
        std::cout << "Population: " << myPopulation;
        if (myPopulation.get_population() < 1) {
            std::cout << "Your population died at year " << i + 1 << std::endl;
            break;
        }
    }
    return 0;
}
