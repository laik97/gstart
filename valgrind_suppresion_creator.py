import sys
import os


def get_valgrind_log_path(arguments: list) -> str:
    path_arg_index = arguments.index("--log_path") + 1
    return sys.argv[path_arg_index]


def get_suppression_blocks_from_log(path) -> list:
    with open(path, "r") as log:
        suppression_blocks = {}
        suppression_block = ""
        catch_mode = False

        for line in log.readlines():
            if "{" in line:
                # start of suppression block
                catch_mode = True

            if catch_mode:
                suppression_block += line

            if "}" in line:
                # end of suppression block
                catch_mode = False
                suppression_blocks[hash(suppression_block)] = suppression_block
                suppression_block = ""

    return suppression_blocks


def save_suppression_block_to_file(blocks: list, save_path: str) -> None:
    with open(save_path, "w") as file:
        for values in blocks.values():
            file.write(values)


def main():
    valgrind_generated_suppression_log_path = get_valgrind_log_path(sys.argv)

    print(
        f"valgrind_generated_suppression_log_path : {valgrind_generated_suppression_log_path}"
    )

    suppression_blocks = get_suppression_blocks_from_log(
        valgrind_generated_suppression_log_path
    )

    print(f"Suppression blocks created : {len(suppression_blocks)}")

    save_suppression_block_to_file(
        suppression_blocks,
        os.path.join(os.getcwd(), "valgrind_nvidia_lib_suppression.supp"),
    )

    print("Done\n")


if __name__ == "__main__":
    main()
