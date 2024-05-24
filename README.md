# DisasterManagement
When disaster hits a nation, the most urgent task is to be able to provide the people affected with what they need as quickly and as efficiently possible. This application manages the list of the items that needs to be shipped to the area. It keeps track of the quantity of each item needed, the number of items on hand, shipping the items and storing the data in a file for future use.

# Running the application
To run the application, download the repository. Then open the command prompt (Windows) or Terminal (Mac) and change the current directory to the downloaded repository. Compile all the files by running the command:

```
g++ -Wall -std=c++11 -g -o ms AidMan.cpp Date.cpp Item.cpp Menu.cpp Perishable.cpp Status.cpp Utils.cpp iProduct.cpp main.cpp
```
After compiling, run the application by using the command,

On Mac :
```
./ms
```
On Windows :
```
ms
```
The input data is contained in the file <b><i>data.dat</i></b>

# Application Design
The application design is based on the Object Oriented Programming (OOP) paradigm:<br>
- Abstraction
- Encapsulation
- Polymorphism
- Inheritance

Along with that, <b>reading</b> and <b>writing</b> data to the file is implemented to keep track of the list of items that needs to be shipped.
### Class Diagram
![DisasterManagement](https://github.com/Ankit16727/DisasterManagement/assets/120432770/66399420-37d7-4c79-beb7-0b378679e074)

# User Interface
### Initializing the database by reading data from file
<img width="1440" alt="LoadingData" src="https://github.com/Ankit16727/DisasterManagement/assets/120432770/83ab872c-d98b-4656-a66b-d9122e1bac06">

### Listing the items 
<img width="1440" alt="ListingItems" src="https://github.com/Ankit16727/DisasterManagement/assets/120432770/926e55d0-2848-4aaf-8c0c-9414099f27cc">

### Adding an item

<img width="1440" alt="AddingItem" src="https://github.com/Ankit16727/DisasterManagement/assets/120432770/dc243ee8-1c1f-4c43-9589-3c6d01dffd42">

### List after the item is added
<img width="1440" alt="ItemAfterAdding" src="https://github.com/Ankit16727/DisasterManagement/assets/120432770/4c9e3dc2-1b5a-4898-911b-afd7dcbb2202">


