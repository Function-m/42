import os
import argparse

def read_markdown(file_path):
    """
    Read the content of the markdown file.
    """
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            return file.read()
    except Exception as e:
        return f"Error reading {file_path}: {e}"

def restore_files_from_markdown(markdown_content):
    """
    Restore files from the markdown content.
    """
    lines = markdown_content.split('\n')
    current_file = None
    file_content = []

    for line in lines:
        if line.startswith("## "):
            # Save the previous file if there was one
            if current_file:
                save_file_content(current_file, "\n".join(file_content))
                file_content = []
            current_file = line[3:]
        elif line.startswith("```"):
            continue
        else:
            file_content.append(line)

    # Save the last file
    if current_file:
        save_file_content(current_file, "\n".join(file_content))

def save_file_content(file_path, content):
    """
    Save content to a file.
    """
    os.makedirs(os.path.dirname(file_path), exist_ok=True)
    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(content)

def main(input_path):
    if os.path.isfile(input_path):
        markdown_content = read_markdown(input_path)
        restore_files_from_markdown(markdown_content)
    else:
        print("Invalid path")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Restore files from a markdown file.")
    parser.add_argument('input_path', type=str, help="The markdown file path to process")
    args = parser.parse_args()

    main(args.input_path)
