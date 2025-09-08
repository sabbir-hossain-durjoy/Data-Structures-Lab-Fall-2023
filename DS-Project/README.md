# 🎟️ Conference Management System  
A **C-based ticket management system** that allows students to request, update, cancel, and manage tickets for a conference. The system uses **queues, stacks, and linked lists** to handle requests, allocate seats, and maintain booking history.  

## 🚀 Features  
✅ Request and confirm tickets  
✏️ Update or cancel existing tickets  
📋 Display all pending ticket requests  
💺 Allocate seats for the conference  
🎫 Display available tickets (with ID, date, time, seat)  
⚙️ Process requests and match with available seats  
📜 View booking history  

## 🛠️ Technologies Used  
- 🖥️ **Programming Language**: C  
- 📊 **Data Structures**: Queue, Stack, Linked List  

## 📂 Project Structure  
📌 `struct Request_queue` → Manages ticket requests from students  
📌 `struct Ticket_stack` → Stores available seats/tickets  
📌 `struct History` → Keeps record of booked tickets  

## 📖 How It Works  
1️⃣ Students request tickets → stored in a **queue**  
2️⃣ Admin allocates seats → stored in a **stack**  
3️⃣ Requests are processed → matched with seats and moved to **history**  
4️⃣ History can be displayed → shows all confirmed bookings  

## 📌 Usage (Menu Options)  
1️⃣ Request for a ticket  
2️⃣ Update or cancel ticket  
3️⃣ Display all requests  
4️⃣ Total available seats (seat allocation)  
5️⃣ Display available tickets  
6️⃣ Process requests and tickets  
7️⃣ Display ticket history  
8️⃣ Exit  

## 📷 Sample Output  
_______________________________________________________  
Choice an option:  
1. Request for a ticket  
2. Update or cancel ticket  
3. Display all requests  
4. Total Available Seats  
5. Display available tickets  
6. Process request and tickets  
7. Ticket history  
8. Exit  
_______________________________________________________  

## 📊 Data Structures / Algorithms  
- 🔄 **Queue** → Manages ticket requests  
- 📚 **Stack** → Handles seat allocation  
- 📝 **Linked List** → Stores booking history  



