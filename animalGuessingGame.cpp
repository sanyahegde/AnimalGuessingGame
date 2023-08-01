/*

SANYA HEGDE 
Animal Guessing Game

Purpose:
This code implements an interactive binary tree-based guessing game. It asks the user a series of yes/no questions to guess an animal. If the guess is correct, it wins, but if it fails, it learns from the user's input and updates the tree for better guesses in future rounds. The game continues until the user decides to stop playing.

*/

//include libraries
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//define struct
struct AnimalNode {
    string data;
    AnimalNode* left;
    AnimalNode* right;

    AnimalNode(const string& data_item, AnimalNode* left_ptr = NULL, AnimalNode* right_ptr = NULL) :
        data(data_item), left(left_ptr), right(right_ptr) {}
};


//update program with userinput
void UpdateTree(AnimalNode* tree, const string& useInput, const string& question, const string& userAnimal) {
    AnimalNode* userAnimal_node = new AnimalNode(userAnimal);
    AnimalNode* new_question_node = new AnimalNode(question);

    string current_useInput = tree->data;
    tree->data = question;//data
    tree->left = new_question_node;
    tree->right = userAnimal_node;

    if (useInput == "yes") {
        new_question_node->left = new AnimalNode(current_useInput);
        new_question_node->right = userAnimal_node;
    }
    else {
        new_question_node->left = userAnimal_node;
        new_question_node->right = new AnimalNode(current_useInput);
    }
}

void PlayGame(AnimalNode* tree) {
    string useInput;

    while (tree->left != NULL && tree->right != NULL) {
        cout << tree->data << " (yes/no): ";
        cin >> useInput;
        if (useInput == "yes") {
            tree = tree->left;
        }
        else {
            tree = tree->right;
        }
    }

    cout << "Is it a(an) " << tree->data << "? (yes/no): ";
    cin >> useInput;

  //print if answered correct
    if (useInput == "yes") {
        cout << "I won! I guessed correct!" << endl;
    }
    else {
      //ask user what animal it is
        cout << "Bummer! I don't know what it is! What animal is it? ";
        string userAnimal;
        cin >> userAnimal;

      //ask user for new yes/no question 
        cout << "Enter a yes/no question to differentiate a " << tree->data << " from a " << userAnimal << ": ";
        string new_question;
        cin.ignore();
        getline(cin, new_question);

      //update program 
        UpdateTree(tree, useInput, new_question, userAnimal);
        cout << "Great! Now I know!" << endl;
    }
}

//main function 
int main() {

    AnimalNode* tree = new AnimalNode("");
  //start game
    cout << "Press enter to start the game." << endl;
    cin.ignore();

  //questions
    tree->data = "Is it a mammal?";
    tree->left = new AnimalNode("Does it have stripes?", new AnimalNode("zebra"), new AnimalNode("cow"));
    tree->right = new AnimalNode("Does it fly?", new AnimalNode("bird"), new AnimalNode("Does it have scales?", new AnimalNode("fish"), new AnimalNode("monkey")));

    tree->right->left->right = new AnimalNode("Does it live in water?", new AnimalNode("penguin"), new AnimalNode("shark"));
    tree->right->right->left = new AnimalNode("Does it live in water?", new AnimalNode("fish"), new AnimalNode("tiger"));
    tree->right->right->right = new AnimalNode("Does it have feathers?", new AnimalNode("ostrich"), new AnimalNode("frog"));
    tree->right->left->left = new AnimalNode("Does it have wings?", new AnimalNode("eagles"), new AnimalNode("moa")); 
    string playAgain = "yes";
    while (playAgain == "yes")
      {
        //print to user
        cout<<endl; 
        cout << "Think of an animal and then answer the question." << endl;
        cin.ignore();
        PlayGame(tree);

        //start game again
        cout << "Want to play again (yes/no): ";
        cin >> playAgain;
    }

    return 0;
}

