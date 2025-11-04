#include <iostream>
#include <string>

// Struct to hold cookware options
struct Cookware
{
    std::string oven{}, skillet{}, grill{};
};

// Struct to hold steak info
struct Steak
{
    int thickness{}, time{};              // in inches (we'll just store 1, 2, 3, etc.)
    std::string cookingMethod{};     // skillet / oven / grill
    std::string doneness{}; 
             // rare / medium-rare, medium
};

// Function prototypes
std::string cookingType(const std::string &skillet,
                        const std::string &oven,
                        const std::string &grill);
int steakSize();
std::string steakDoneness();
int cookingTime(const std::string &method, int thickness, const std::string &doneness);


int main()
{
    Steak steak;
    Cookware cookware;

    // just filling these so we have named options
    cookware.skillet = "skillet";
    cookware.oven    = "oven";
    cookware.grill   = "grill";

    // ask user how they're cooking it
    steak.cookingMethod = cookingType(cookware.skillet, cookware.oven, cookware.grill);

    // ask user how thick
    steak.thickness = steakSize();

    // ask user doneness
    steak.doneness = steakDoneness();

    steak.time = cookingTime(steak.cookingMethod, steak.thickness, steak.doneness);

    // show what we collected
    std::cout << "\n--- Steak Summary ---\n";
    std::cout << "Cooking method: " << steak.cookingMethod << "\n";
    std::cout << "Thickness: " << steak.thickness << " inch(es)\n";
    std::cout << "Doneness: " << steak.doneness << "\n";
    std::cout << "Cook time: " << steak.time << "\n";


    return 0;
}

// Ask user for type of cooking method
std::string cookingType(const std::string &skillet,
                        const std::string &oven,
                        const std::string &grill)
{
    std::cout << "Enter how you will be cooking the steak " 
        "(" << skillet << ", " << oven << ", " << grill << "): ";
    std::string cookType;
    std::getline(std::cin >> std::ws, cookType);

    // Makes it simple by checking the three options
    if (cookType == skillet)
    {
        return skillet;
    }
    else if (cookType == oven)
    {
        return oven;
    }
    else if (cookType == grill)
    {
        return grill;
    }
    else
    {
        // If something is typed by random or incorrect, just default to skillet
        std::cout << "Unknown method. Defaulting to skillet.\n";
        return skillet;
    }
}

// Ask user for thickness of steak
int steakSize()
{
    int size{};
    std::cout << "How thick is the steak? (1, 2, 3): ";
    std::cin >> size;
    // very basic validation
    if (size <= 0)
    {
        std::cout << "Invalid size, setting to 1.\n";
        size = 1;
    }
    return size;
}

// Ask for doneness level
std::string steakDoneness()
{
    std::cout << "Enter desired doneness (rare, medium rare, medium): ";
    std::string d;
    std::getline(std::cin >> std::ws, d);
    return d;
}

int cookingTime(const std::string &method, int thickness, const std::string &doneness)
{
    int time{};

    if (method == "skillet" && doneness == "rare")
        time = 3 * thickness;
    else if (method == "skillet" && doneness == "medium rare")
        time = 4 * thickness;
    else if (method == "skillet" && doneness == "medium")
        time = 5 * thickness;
    else if (method == "skillet")                                           // Plan on using a std::map in the future
        time = 6 * thickness;
    else if (method == "oven" && doneness == "rare")
        time = 8 * thickness;
    else if (method == "oven" && doneness == "medium rare")
        time = 10 * thickness;
    else if (method == "oven" && doneness == "medium")
        time = 12 * thickness;
    else if (method == "oven")
        time = 14 * thickness;
    else if (method == "grill" && doneness == "rare")
        time = 5 * thickness;
    else if (method == "grill" && doneness == "medium rare")
        time = 6 * thickness;
    else if (method == "grill" && doneness == "medium")
        time = 7 * thickness;
    else if (method == "grill")
        time = 8 * thickness;
    else
        time = 5 * thickness;

    return time;
}


