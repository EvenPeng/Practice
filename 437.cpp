#include <algorithm>
#include <iostream>
#include <vector>

#define Length int
#define Width int
#define Height int

struct Block {
    Length l;
    Width  w;
    Height h, max_h;
};

std::vector<Block> blocks(90);

bool compare_block(const Block &x, const Block &y)
{
    return x.l == y.l ? (x.w == y.w ? x.h > y.h : x.w > y.w) : x.l > y.l;
}

bool same_block(const Block &x, const Block &y)
{
    return x.l == y.l && x.w == y.w && x.h == y.h;
}

void write_block(int i, int l, int w, int h)
{
    blocks[i].l     = l;
    blocks[i].w     = w;
    blocks[i].h     = h;
    blocks[i].max_h = h;
}

void read_block(int index)
{
    std::vector<int> dim(3);
    std::cin >> dim[0] >> dim[1] >> dim[2];
    sort(dim.begin(), dim.end());
    write_block(index, dim[2], dim[1], dim[0]);
    write_block(index + 1, dim[2], dim[0], dim[1]);
    write_block(index + 2, dim[1], dim[0], dim[2]);
}

int main(void)
{
    int    case_index = 0;
    int    num_blocks;
    Height max_h;
    while (1) {
        std::cin >> num_blocks;
        if (!num_blocks) break;

        for (int i = 0; i < num_blocks; ++i)
            read_block(i * 3);
        num_blocks *= 3;

        std::sort(blocks.begin(), blocks.begin() + num_blocks, compare_block);
        num_blocks = int(std::unique(blocks.begin(),
                                     blocks.begin() + num_blocks, same_block) -
                         blocks.begin());
        max_h      = 0;
        for (int i = 0; i < num_blocks; ++i) {
            int j = i + 1;
            while (j < num_blocks && blocks[i].l == blocks[j].l)
                ++j;
            while (j < num_blocks) {
                if (blocks[i].w > blocks[j].w) {
                    blocks[j].max_h = std::max(blocks[j].max_h,
                                               blocks[i].max_h + blocks[j].h);
                    max_h           = std::max(max_h, blocks[j].max_h);
                }
                ++j;
            }
        }

        std::cout << "Case " << ++case_index << ": maximum height = " << max_h
                  << std::endl;
    }

    return 0;
}
