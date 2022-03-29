from collections import Counter


def find_char_freq(text):
    result = dict()
    with open(text, 'r') as f:
        for line in f.readlines():
            line = line.lower()
            for i in line:
                if i.isalpha():
                    if i in result:
                        result[i] += 1
                    else:
                        result.update({i: 1})
    return result


class Node:
    def __init__(self):
        self.frequency = 0
        self.name = None
        self.lchild = None
        self.rchild = None
        self.code = None

    def __lt__(self, other):
        return self.frequency < other.frequency


# establish the Huffman Tree
def estblishHuffmanTree(info_dict):
    # output: the base node
    node_list = []
    for i in info_dict:
        a = Node()
        a.frequency = info_dict[i]
        a.name = i
        node_list.append(a)
    while len(node_list) > 1:
        node_list.sort(reverse=True)
        node_1 = node_list.pop()
        node_2 = node_list.pop()
        new_node = Node()
        new_node.frequency = node_1.frequency + node_2.frequency
        new_node.lchild = node_1
        new_node.rchild = node_2
        node_list.append(new_node)
    return new_node


def encode(node, rst_dict, code):
    if node.name:
        rst_dict.update({node.name: code})
        return
    code += '0'
    encode(node.lchild, rst_dict, code)
    code = code[:-1]
    code += '1'
    encode(node.rchild, rst_dict, code)
    return rst_dict


def encode_text(code_dict, text, code_text):
    string = ''
    with open(text, 'r') as f:
        for line in f.readlines():
            line = line.lower()
            for i in line:
                if i.isalpha():
                    string += code_dict[i]
                else:
                    string += '\n'
    with open(code_text, 'w') as f:
        f.write(string)


def decode(text_de, result_address, base_node):
    text_string = ''
    a = base_node
    with open(text_de, 'r') as f:
        for line in f.readlines():
            for i in line:
                if i == '0':
                    b = a.lchild
                    if b.name:
                        text_string += b.name
                        a = base_node
                    else:
                        a = b
                elif i == '1':
                    b = a.rchild
                    if b.name:
                        text_string += b.name
                        a = base_node
                    else:
                        a = b
                else:
                    text_string += '\n'
    with open(result_address, 'w') as f:
        f.write(text_string)

# TODO: print encodings with issue, needs to fix.
def print_dict(d):
    print(sorted(d.items(), key=lambda x: int(x[1])))


if __name__ == '__main__':
    text = "SourceFile.txt"
    char_freq = find_char_freq(text)
    print_dict(char_freq)

    base_node = estblishHuffmanTree(char_freq)
    code_dict = encode(base_node, {}, '')
    print_dict(code_dict)

    code_text = "ResultFile.txt"
    encode_text(code_dict, text, code_text)

    de_address = "decode.txt"
    decode(code_text, de_address, base_node)
