# Smart Food Delivery Route Optimization System

## About the Project

The Smart Food Delivery Route Optimization System is a C-based Data Structures and Algorithms project designed to manage food delivery operations efficiently.

The system manages restaurants, customers, food orders, normal deliveries, priority deliveries, delivery locations, shortest routes, estimated delivery time, order searching, completed delivery history, and order information stored in a file.

The project demonstrates how fundamental Data Structures and Algorithms can be applied to solve a practical food delivery management problem.

## Project Type

C Programming + Data Structures and Algorithms

## Key Features

* Restaurant management
* Customer management
* Food order management
* Normal order processing
* Priority order processing
* Delivery route optimization
* Shortest path calculation
* Estimated delivery time calculation
* Order searching
* Completed delivery history
* File-based order storage
* Delivery dashboard

## Data Structures and Algorithms

The project uses the following Data Structures and Algorithms:

* Structures
* Arrays
* Queue
* Priority Queue
* Linked List concept
* Graph
* Adjacency Matrix
* Dijkstra's Shortest Path Algorithm
* Linear Search
* File Handling
* ETA Calculation

## Restaurant Management

Restaurant information is stored using structures and arrays.

Each restaurant contains:

* Restaurant ID
* Restaurant Name
* Restaurant Area

The system provides sample restaurants and also allows new restaurants to be added during execution.

## Customer Management

Customer information is managed using structures and arrays.

Each customer contains:

* Customer ID
* Customer Name
* Customer Area

The system provides sample customers and also allows new customers to be added.

## Order Management

The system manages food delivery orders using an Order structure.

Each order contains:

* Order ID
* Restaurant ID
* Customer ID
* Food Item
* Priority
* Status

Orders can be processed through either the normal queue or priority queue.

## Normal Queue

Normal delivery orders are processed using a Queue.

The queue follows the FIFO principle:

**First In, First Out**

Example:

```text
101 → 103 → Delivery
```

The order that enters first is processed first.

### Queue Complexity

* Insertion: O(1)
* Deletion: O(1)

## Priority Queue

Priority delivery orders are processed using a Priority Queue.

Orders with higher priority are processed before orders with lower priority.

Example:

```text
102 — Priority 5
104 — Priority 4
```

Order 102 is processed before Order 104 because it has a higher priority.

### Priority Queue Complexity

* Insertion: O(n)
* Deletion: O(n)

## Delivery Route Optimization

The delivery network is represented using a weighted graph.

* Vertices represent delivery locations.
* Edges represent roads.
* Edge weights represent distances.
* An adjacency matrix is used to store the road distances.

### Road Network

```text
A ↔ B = 4 km
A ↔ C = 7 km
B ↔ C = 3 km
B ↔ D = 5 km
C ↔ D = 2 km
C ↔ E = 6 km
D ↔ F = 4 km
E ↔ F = 3 km
```

## Dijkstra's Shortest Path Algorithm

Dijkstra's Algorithm is used to find the shortest delivery route between two locations.

The main steps are:

1. Select the source location.
2. Initialize the distances.
3. Select the unvisited location with the minimum distance.
4. Update the distances of neighboring locations.
5. Repeat the process.
6. Reconstruct the shortest route.

### Example

Source:

```text
A
```

Destination:

```text
F
```

Shortest route:

```text
A → B → D → F
```

Total distance:

```text
13 km
```

### Complexity

```text
O(V²)
```

## Order Searching

The system uses Linear Search to find an order using its Order ID.

Example:

```text
Search Order ID: 102
```

Result:

```text
Order ID: 102
Food: Biryani
Priority: 5
Status: Ready
```

### Complexity

```text
O(n)
```

## Completed Delivery History

Completed deliveries are maintained using a linked-list concept.

Example:

```text
Order 101 → Order 103 → NULL
```

This allows completed orders to be maintained as a delivery history.

## ETA Calculation

The estimated delivery time is calculated using the distance and delivery speed.

### Formula

```text
ETA = Distance / Speed × 60
```

### Example

```text
Distance = 13 km
Speed = 30 km/h
```

Therefore:

```text
ETA ≈ 26 minutes
```

### Complexity

```text
O(1)
```

## File Handling

Order information is stored using file handling.

The project uses:

```text
orders.txt
```

The stored information includes:

* Order ID
* Restaurant ID
* Customer ID
* Food Item
* Priority
* Status

The project demonstrates the following C file-handling functions:

```c
fopen()
fprintf()
fgets()
fclose()
```

## Delivery Dashboard

The delivery dashboard displays the current status of restaurants, customers, orders, and deliveries.

Example:

```text
Restaurants: 4
Customers: 4
Total Orders: 4
Normal Pending: 2
Priority Pending: 2
Completed: 0
```

After one delivery:

```text
Normal Pending: 1
Priority Pending: 2
Completed: 1
```

## Project Modules

The project is maintained in a single folder and contains the following C source and header files:

```text
restaurant.c
restaurant.h

customer.c
customer.h

order.c
order.h

queue.c
queue.h

priority_queue.c
priority_queue.h

graph.c
graph.h

eta.c
eta.h

search.c
search.h

history.c
history.h

storage.c
storage.h

main.c
```

## Project Flow

```text
Restaurant
     ↓
Customer
     ↓
Order
     ↓
Normal Queue / Priority Queue
     ↓
Delivery Processing
     ↓
Delivery Location
     ↓
Graph
     ↓
Dijkstra Shortest Route
     ↓
ETA Calculation
     ↓
Completed Delivery
     ↓
History + Dashboard + File Storage
```

## Algorithm Complexity

| Operation                | Technique        | Complexity |
| ------------------------ | ---------------- | ---------- |
| Display Restaurants      | Array            | O(n)       |
| Display Customers        | Array            | O(n)       |
| Queue Insertion          | Queue            | O(1)       |
| Queue Deletion           | Queue            | O(1)       |
| Priority Queue Insertion | Priority Queue   | O(n)       |
| Priority Queue Deletion  | Priority Queue   | O(n)       |
| Graph Storage            | Adjacency Matrix | O(V²)      |
| Shortest Route           | Dijkstra         | O(V²)      |
| Order Search             | Linear Search    | O(n)       |
| ETA Calculation          | Arithmetic       | O(1)       |

## Advantages

* Organized restaurant and customer management
* Efficient order processing
* Priority handling for urgent orders
* Shortest delivery route calculation
* Estimated delivery time
* Order searching
* Completed delivery history
* File-based order storage
* Modular C implementation
* Practical application of Data Structures and Algorithms

## How to Run

### Compile Using GCC

Open the terminal in the project folder and compile the C source files:

```bash
gcc *.c -o food_delivery
```

### Run on Windows

```bash
food_delivery.exe
```

### Run on Linux

```bash
./food_delivery
```

## Project Structure

```text
Smart-Food-Delivery-Route-Optimization-System/
│
├── restaurant.c
├── restaurant.h
├── customer.c
├── customer.h
├── order.c
├── order.h
├── queue.c
├── queue.h
├── priority_queue.c
├── priority_queue.h
├── graph.c
├── graph.h
├── eta.c
├── eta.h
├── search.c
├── search.h
├── history.c
├── history.h
├── storage.c
├── storage.h
├── main.c
├── orders.txt
└── README.md
```

## Future Enhancements

The system can be further extended with:

* User login
* Dynamic order creation
* Order cancellation
* Delivery status updates
* Circular queue
* Larger delivery networks
* Graphical user interface
* Real-time location tracking
* Advanced ETA prediction

## Conclusion

The Smart Food Delivery Route Optimization System demonstrates the use of C programming and Data Structures and Algorithms in a practical food delivery management application.

The project combines structures, arrays, queues, priority queues, linked-list concepts, graphs, adjacency matrices, Dijkstra's Shortest Path Algorithm, linear search, ETA calculation, and file handling to organize and manage the delivery process.

The project provides a practical demonstration of how Data Structures and Algorithms can be used to manage orders, process deliveries, optimize routes, calculate delivery time, maintain delivery history, and store order information.
