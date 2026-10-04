#include <iostream>
#include <string>
using namespace std;

// Structure to represent each song node in the doubly linked list
struct Node {
    string song;
    string artist;
    Node* next;
    Node* prev;

    // Constructor to initialize node data and pointer attributes
    Node(string s, string a) {
        song = s;
        artist = a;
        next = NULL;
        prev = NULL;
    }
};

// Class to manage playlist operations using a doubly linked list
class MusicPlayer {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    // Constructor to initialize an empty playlist
    MusicPlayer() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    // Function to add a new song at the end of the playlist
    void addSong(string songName, string artistName) {
        Node* newNode = new Node(songName, artistName);

        // If the playlist is currently empty
        if (head == NULL) {
            head = tail = current = newNode;
        } 
        // If the playlist already contains songs
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Added song: " << songName << " - " << artistName << endl;
    }

    // Function to navigate to and play the next song
    void playNext() {
        if (current == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        if (current->next != NULL) {
            current = current->next;
            cout << "Playing Next: " << current->song << " (" << current->artist << ")" << endl;
        } else {
            cout << "You have reached the last song in the playlist!" << endl;
        }
    }

    // Function to navigate to and play the previous song
    void playPrevious() {
        if (current == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        if (current->prev != NULL) {
            current = current->prev;
            cout << "Playing Previous: " << current->song << " (" << current->artist << ")" << endl;
        } else {
            cout << "You are at the first song; cannot go back further!" << endl;
        }
    }

    // Function to display details of the currently playing track
    void showCurrent() {
        if (current != NULL) {
            cout << "Currently Playing: " << current->song << " by " << current->artist << endl;
        } else {
            cout << "No song is currently playing." << endl;
        }
    }

    // Function to print the entire playlist along with the active track marker
    void displayPlaylist() {
        if (head == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "\n===== PLAYLIST =====" << endl;
        while (temp != NULL) {
            if (temp == current) {
                cout << "-> " << temp->song << " - " << temp->artist << " [NOW PLAYING]" << endl;
            } else {
                cout << "   " << temp->song << " - " << temp->artist << endl;
            }
            temp = temp->next;
        }
        cout << "====================\n" << endl;
    }
};

int main() {
    MusicPlayer player;

    // Adding songs to the playlist
    player.addSong("Shape of You", "Ed Sheeran");
    player.addSong("Blinding Lights", "The Weeknd");
    player.addSong("Levitating", "Dua Lipa");

    // Display initial playlist
    player.displayPlaylist();

    // Show initial active song
    player.showCurrent();
    
    // Test forward navigation
    player.playNext();
    player.playNext();
    
    // Attempt forward navigation at the end of playlist
    player.playNext();

    // Test backward navigation
    player.playPrevious();

    // Display updated playlist status
    player.displayPlaylist();

    return 0;
}
