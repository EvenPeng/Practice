#include <cmath>
#include <cstring>
#include <iostream>
#include <string>

struct Tree {
    bool        is_end;
    std::string nodes;
    int         idx, pos, level, count[10];
};

void init_tree(Tree &tree)
{
    tree.is_end = false;
    tree.idx    = 0;
    tree.pos    = 0;
    tree.level  = 0;
    memset(tree.count, 0, sizeof(tree.count));
}

char get_node(const Tree &tree) { return tree.nodes[tree.pos]; }

void next(Tree &tree)
{
    ++tree.count[tree.level];
    if (tree.nodes[tree.pos] == 'p') {
        tree.idx = tree.idx * 4 + 1;
        ++tree.level;
        tree.count[tree.level] = 0;
    }
    else {
        while (tree.count[tree.level] == 4) {
            tree.idx = (tree.idx - 1) / 4;
            --tree.level;
        }
        ++tree.idx;
    }
    ++tree.pos;
    tree.is_end = (tree.pos >= tree.nodes.size());
}

int pixel_size(int level) { return 1024 / pow(4, level); }

int count_pixel(Tree &tree, int til)
{
    if (get_node(tree) == 'f') return pixel_size(tree.level);
    int num_pixels = 0;

    while (!tree.is_end && tree.idx != til) {
        if (get_node(tree) == 'f') num_pixels += pixel_size(tree.level);
        next(tree);
    }

    return num_pixels;
}

int merge_pixel(Tree &treeA, Tree &treeB)
{
    int num_pixels = 0;

    while (!treeA.is_end && !treeB.is_end) {
        if (get_node(treeA) == 'f' || get_node(treeB) == 'f') {
            num_pixels += pixel_size(treeA.level);
            next(treeA);
            next(treeB);
            if (treeA.idx < treeB.idx) {
                while (!treeB.is_end && treeA.idx != treeB.idx)
                    next(treeB);
            }
            else if (treeA.idx > treeB.idx) {
                while (!treeA.is_end && treeA.idx != treeB.idx)
                    next(treeA);
            }
        }
        else if (get_node(treeA) == 'p' && get_node(treeB) == 'e') {
            next(treeB);
            num_pixels += count_pixel(treeA, treeB.idx);
        }
        else if (get_node(treeB) == 'p' && get_node(treeA) == 'e') {
            next(treeA);
            num_pixels += count_pixel(treeB, treeA.idx);
        }
        else {
            next(treeA);
            next(treeB);
        }
    }

    return num_pixels;
}

int main(void)
{
    int  num_cases;
    Tree treeA, treeB;

    std::cin >> num_cases;
    while (num_cases--) {
        init_tree(treeA);
        init_tree(treeB);
        std::cin >> treeA.nodes >> treeB.nodes;
        std::cout << "There are " << merge_pixel(treeA, treeB)
                  << " black pixels." << std::endl;
    }

    return 0;
}
