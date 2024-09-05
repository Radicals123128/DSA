import java.util.Scanner;

class Node {
    int data;
    Node next;

    // Constructor to initialize node with data
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Prompt for the number of nodes
        System.out.print("Enter the number of nodes: ");
        int n_data = sc.nextInt();

        // Initialize the head of the linked list
        Node head = null;
        Node current = null;

        // Create nodes and build the linked list
        for (int i = 0; i < n_data; i++) {
            System.out.print("Enter data for node " + (i + 1) + ": ");
            int data = sc.nextInt();
            Node newNode = new Node(data);
            
            if (head == null) {
                // First node
                head = newNode;
                current = head;
            } else {
                // Append to the list
                current.next = newNode;
                current = newNode;
            }
        }

        // Display the linked list
        System.out.println("Linked List:");
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
        
        sc.close();
    }
}
