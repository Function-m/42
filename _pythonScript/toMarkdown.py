import os
import argparse

def list_files(directory):
    """
    Recursively list all files in the given directory.
    """
    files_list = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            files_list.append(os.path.join(root, file))
    return files_list

def read_file_content(file_path):
    """
    Read the content of a file.
    """
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            return file.read()
    except Exception as e:
        return f"Error reading {file_path}: {e}"

def generate_markdown(file_list, language):
    """
    Generate markdown content from a list of files, including their contents.
    """
    markdown_content = ""
    for file in file_list:
        markdown_content += f"## {file}\n"
        file_content = read_file_content(file)
        markdown_content += f"```{language}\n{file_content}\n```\n"
    return markdown_content

def save_markdown(content, output_file):
    """
    Save the markdown content to an output file.
    """
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)

def main(input_path, language):
    output_file = "_toMarkdown.md"
    if os.path.isdir(input_path):
        files_list = list_files(input_path)
        markdown_content = generate_markdown(files_list, language)
        save_markdown(markdown_content, output_file)
    elif os.path.isfile(input_path):
        markdown_content = generate_markdown([input_path], language)
        save_markdown(markdown_content, output_file)
    else:
        print("Invalid path")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate a markdown file listing all files and their contents in a directory.")
    parser.add_argument('input_path', type=str, help="The directory or file path to process")
    parser.add_argument('language', type=str, help="The programming language for syntax highlighting in markdown")
    args = parser.parse_args()

    main(args.input_path, args.language)
