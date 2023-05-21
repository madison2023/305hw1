//
//  feed.c creates the feed of posts
//  
//
//  Created by Rachel Madison on 9/9/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "feed.h"
#include "post.h"

/// Creates a new feed object on the heap
feed* create_feed(int max_p) {
    feed * feedptr;
    //allocating memory for the feedptr
    feedptr = (feed *)malloc(sizeof(feed));
    feedptr->num_posts = 0;
    
    //making sure max_posts is at least 10
    if(max_p < 10){
        feedptr->max_posts = 10;
    }
    else {
        feedptr->max_posts = max_p;
    }
    //allocating memory for posts
    feedptr->posts = (post *)malloc(feedptr->max_posts * sizeof(post));
    return feedptr;
}

/// Adds a post to the feed.
/// Returns 0 on success, -1 if f or p is NULL, and -2 if no more
/// room.
int add_post(feed* f, post* p) {
    if(f == NULL || p == NULL) {
        return -1;
    }
    else if ( f->num_posts >= f->max_posts) {
        return -2;
    }
    else {
        f->posts[f->num_posts] = *p;
        f->num_posts++;
        return 0;
    }
}

/// Deletes the i'th post from f.
/// Returns 0 on success, -1 if f is NULL, and -2 if no such index
int delete_post(feed* f, int i) {
    if(f == NULL){
        return -1;
    }
    else if ( i >= f->num_posts || i < 0) {
        return -2;
    }
    else {
//deletes post by setting it equal to the next one and keeps shifting so the rest are left the same just one index over
        for (int j = i; j < f->num_posts; j++) {
            f->posts[j] = f->posts[j+1];
        }
        f->num_posts--;
        return 0;
    }
}

/// Prints the feed to stdout
void print_feed(feed* f) {
    printf("## Viral Posts ##\n");
    for (int i = 0; i < f->num_posts; i++){
        if (post_is_viral(&f->posts[i]) == 1) {
            print_post(&f->posts[i]);
            for(int j = 0; j < 50; j++){
                //printing 50 dashes
                printf("-");
            }
            //new line to make format right
            printf("\n");
        }
    }

    
    printf("# Other Posts #\n");
    //goes through all of posts and
    //prints the ones that aren't viral
    for (int i = 0; i < f->num_posts; i++){
        if (post_is_viral(&f->posts[i]) != 1) {
            print_post(&f->posts[i]);
            for(int j = 0; j < 50; j++){
                printf("-");
            }
            printf("\n");
        }
    }
}

/// Frees the memory for a particular feed object
void free_feed(feed* f) {
    free(f->posts);
    free(f);
}
