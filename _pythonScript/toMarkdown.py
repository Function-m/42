import os
import argparse

# 설정 섹션
exclude_extensions = ['o', 'd']  # 제외할 파일 확장자 목록
exclude_files = ['README.md', 'Makefile', 'ircserv_debug', 'ircserv']  # 제외할 파일명 목록
extension_to_language = {
    'py': 'python',
    'js': 'javascript',
    'hpp': 'cpp',
    'md': 'markdown',
    'txt': 'text',
    'sh': 'bash',
    # 필요한 확장자와 언어 매핑 추가
}
output_file = "_toMarkdown.md"  # 출력 마크다운 파일 이름

def list_files(directory):
    """
    지정된 디렉토리 내의 모든 파일을 재귀적으로 나열합니다.
    """
    files_list = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_extension = os.path.splitext(file)[1].lstrip('.')
            if file_extension not in exclude_extensions and file not in exclude_files:
                files_list.append(os.path.join(root, file))
    return files_list

def read_file_content(file_path):
    """
    파일의 내용을 읽습니다.
    """
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            return file.read()
    except Exception as e:
        return f"{file_path}을(를) 읽는 중 오류 발생: {e}"

def determine_language(file_extension, file_name):
    """
    파일 확장자에 따라 프로그래밍 언어를 결정합니다.
    """
    file_extension = file_extension.lstrip('.')
    return extension_to_language.get(file_extension, file_extension or file_name)

def generate_markdown(file_list):
    """
    파일 목록에서 마크다운 콘텐츠를 생성합니다.
    """
    markdown_content = ""
    for file in file_list:
        file_name, file_extension = os.path.splitext(file)
        language = determine_language(file_extension, os.path.basename(file_name))
        markdown_content += f"### {file}\n"
        file_content = read_file_content(file)
        markdown_content += f"```{language}\n{file_content}\n```\n"
    return markdown_content

def save_markdown(content, output_file):
    """
    생성된 마크다운 콘텐츠를 출력 파일에 저장합니다.
    """
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)

def main(input_path):
    if os.path.isdir(input_path):
        files_list = list_files(input_path)
        markdown_content = generate_markdown(files_list)
        save_markdown(markdown_content, output_file)
    elif os.path.isfile(input_path):
        file_extension = os.path.splitext(input_path)[1].lstrip('.')
        if file_extension not in exclude_extensions and os.path.basename(input_path) not in exclude_files:
            markdown_content = generate_markdown([input_path])
            save_markdown(markdown_content, output_file)
        else:
            print(f"{input_path} 파일은 확장자 또는 파일명에 의해 제외되었습니다.")
    else:
        print("유효하지 않은 경로입니다.")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="지정된 디렉토리 내의 모든 파일과 그 내용을 나열하는 마크다운 파일을 생성합니다.")
    parser.add_argument('input_path', type=str, help="처리할 디렉토리 또는 파일 경로")
    args = parser.parse_args()

    main(args.input_path)
