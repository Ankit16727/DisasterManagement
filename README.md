# DisasterManagement
When disaster hits a nation, the most urgent task is to be able to provide the people affected with what they need as quickly and as efficiently possible. This application manages the list of the items that needs to be shipped to the area. It keeps track of the quantity of each item needed, the number of items on hand, shipping the items and storing the data in a file for future use.

# Running the application
To run the application, download the repository. Then open the command prompt (Windows) or Terminal (Mac) and change the current directory to the downloaded repository. Compile all the files by running the command:

```
g++ -Wall -std=c++11 -g -o ms AidMan.cpp Date.cpp Item.cpp Menu.cpp Perishable.cpp Status.cpp Utils.cpp iProduct.cpp main.cpp

```
