/* CS 305, Fall 2020 Homework 1
 * author: Aaron Moss
 * 
 * Creates feeds and posts and tests them.
 *
 * Compile with command:
 *   gcc -g -o feed feed.c post.c main.c
 *
 * Run with command:
 *   ./feed
 */

#include <stdio.h>
#include "feed.h"
#include "post.h"

/* prototypes */
void run_test();
void run_test2();
void run_test3();
void run_test4();

/* left off command-line parameters because unused for this program 
 */
int main() {
    run_test();
}

/* runs a test, creating feeds and adding/deleting posts
 * DO NOT EDIT THIS FUNCTION; add your own tests in separate 
 * functions
 */
void run_test() {
    // create two feeds (using pointers for easier modification)
    feed* maria = create_feed(15);
    feed* james = create_feed(0); // defaulted to 10

    // set up some posts to add to both feeds (using values for 
    // more straightforward copying)
    post post0 = create_post("Aaron Moss", 50, "Welcome to CS 305!");
    post post1 = create_post("Aaron Moss", 5, "Java is fun!");
    post post2 = create_post("Aaron Moss", 25, 
        "I love data structures!");
    post post3 = create_post("Maria Nieto", 16, 
        "Is Dr. Moss always so enthusiastic?");
    post post4 = create_post("James Hall", 5, 
        "Can I get some help with arrays?");
    post post5 = create_post("Youngster", 128, 
        "I like shorts! They're comfy and easy to wear!");
    post post6 = create_post("Patrick Stewart", 1024, "Make it so!");
    post post7 = create_post("Jane Austen", 20, 
        "It is a truth universally acknowledged...");
    post postX = create_post("Aaron Moss", 0, "Tihs has a typo...");

    // add posts to both feeds, removing typo post in the middle
    // (posts are passed by pointer so that they aren't copied twice:
    // once into add_post(), once into the feed)
    add_post(maria, &post0);
    add_post(maria, &post1);
    add_post(maria, &post2);
    add_post(maria, &postX);
    // oops, delete last post
    delete_post(maria, maria->num_posts - 1); 
    // continue adding
    add_post(maria, &post4);
    add_post(maria, &post6);

    add_post(james, &post0);
    add_post(james, &post1);
    add_post(james, &post2);
    add_post(james, &post3);
    add_post(james, &post5);
    add_post(james, &post7);

    // display feeds
    printf("\n# Maria's Feed #\n\n");
    print_feed(maria);
    printf("\n# James' Feed #\n\n");
    print_feed(james);

    // free memory
    free_feed(maria);
    free_feed(james);
}

//testing long name
void run_test2() {
    //creating feed
    feed* maria = create_feed(15);
    
    post post0 = create_post("supercalifragilisticexpialidocious", 50, "Welcome to CS 305!");
    
    add_post(maria, &post0);
    
    printf("\n# Maria's Feed #\n\n");
    print_feed(maria);
    
    free_feed(maria);
}

//testing NULL parameters
void run_test3() {
    //creating feed
    feed* maria = create_feed(15);
    
    post post0 = create_post(NULL, 50, NULL);
    
    add_post(maria, &post0);
    
    printf("\n# Maria's Feed #\n\n");
    print_feed(maria);
    
    free_feed(maria);
}

//testing indices for add_post()
void run_test4() {
    feed* maria = create_feed(10);
    
    post post0 = create_post("Aaron Moss", 50, "Welcome to CS 305!");
    post post1 = create_post("Aaron Moss", 5, "Java is fun!");
    post post2 = create_post("Aaron Moss", 25,
        "I love data structures!");
    post post3 = create_post("Maria Nieto", 16,
        "Is Dr. Moss always so enthusiastic?");
    post post4 = create_post("James Hall", 5,
        "Can I get some help with arrays?");
    post post5 = create_post("Youngster", 128,
        "I like shorts! They're comfy and easy to wear!");
    post post6 = create_post("Patrick Stewart", 1024, "Make it so!");
    post post7 = create_post("Jane Austen", 20,
        "It is a truth universally acknowledged...");
    
    add_post(maria, &post0);
    add_post(maria, &post1);
    add_post(maria, &post2);
    add_post(maria, &post4);
    add_post(maria, &post6);
    add_post(maria, &post0);
    add_post(maria, &post1);
    add_post(maria, &post2);
    add_post(maria, &post4);
    add_post(maria, &post6);
    //this is the 11th post so it should not print
    add_post(maria, &post6);

    
    
    printf("\n# Maria's Feed #\n\n");
    print_feed(maria);
    
    free_feed(maria);
}
