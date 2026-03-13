#!/usr/bin/env python3
import subprocess
import re
import os

def extract_text(html):
    text = re.sub(r'<[^>]+>', '', html)
    text = text.replace('&nbsp;', ' ')
    text = text.replace('&amp;', '&')
    text = text.replace('&lt;', '<')
    text = text.replace('&gt;', '>')
    text = text.replace('&quot;', '"')
    return text

# 章节与EPUB文件的映射关系
chapter_files = {
    1: 'text/part0005.html',
    2: 'text/part0006.html',
    3: 'text/part0007.html',
    4: 'text/part0008.html',
    5: 'text/part0009.html',
    6: 'text/part0010.html',
    7: 'text/part0011.html',
    8: 'text/part0012.html',
    9: 'text/part0013.html',
    10: 'text/part0014.html',
    11: 'text/part0015.html',
    12: 'text/part0016.html',
    13: 'text/part0017.html',
    14: 'text/part0018.html',
    15: 'text/part0019.html',
    16: 'text/part0020.html',
    17: 'text/part0021.html',
    18: 'text/part0022.html',
}

# 各章节编程练习的起始节号
exercise_sections = {
    1: '1.8',
    2: '2.8',
    3: None,  # 第3章没有编程练习
    4: '4.14',
    5: '5.9',
    6: '6.18',
    7: '7.11',
    8: '8.8',
    9: '9.14',
    10: '10.11',
    11: '11.11',
    12: '12.8',
    13: '13.10',
    14: '14.10',
    15: '15.21',
    16: '16.13',
    17: '17.10',
    18: '18.8',
}

import os

script_dir = os.path.dirname(os.path.abspath(__file__))
project_dir = os.path.dirname(script_dir)
exercises_dir = os.path.join(project_dir, 'exercises')

for ch in range(1, 19):
    ch_dir = f'{exercises_dir}/chapter_{ch:02d}'
    os.makedirs(ch_dir, exist_ok=True)
    
    readme_path = f'{ch_dir}/README.md'
    
    with open(readme_path, 'w', encoding='utf-8') as f:
        f.write(f"# 第{ch}章 - 编程练习\n\n")
        
        section = exercise_sections.get(ch)
        if section is None:
            f.write("**注意：本章在《C与指针》原书中没有编程练习部分。**\n\n")
            f.write("本章只有\"问题\"（思考题），没有\"编程练习\"。\n")
            print(f"✓ 第{ch}章 无编程练习")
            continue
        
        # 从EPUB中提取
        epub_file = chapter_files[ch]
        cmd = f'unzip -p "C和指针 - [美]Kenneth A. Reek.epub" {epub_file}'
        result = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd=project_dir)
        
        if result.returncode != 0:
            f.write("（提取失败）\n")
            print(f"✗ 第{ch}章 提取失败")
            continue
        
        text = extract_text(result.stdout)
        
        # 找到编程练习部分
        start_pattern = f'{section}　编程练习'
        start_idx = text.find(start_pattern)
        
        if start_idx == -1:
            f.write("（未找到编程练习内容）\n")
            print(f"✗ 第{ch}章 未找到内容")
            continue
        
        # 找到下一章的开始位置作为结束
        next_ch = ch + 1
        if next_ch <= 18:
            end_pattern = f'第{next_ch}章'
        else:
            end_pattern = '[1]'  # 最后一章用注释开始作为结束
        
        end_idx = text.find(end_pattern, start_idx)
        if end_idx == -1:
            end_idx = len(text)
        
        content = text[start_idx:end_idx].strip()
        
        # 清理内容 - 移除末尾的注释标记
        note_idx = content.find('\n  [1]')
        if note_idx != -1:
            content = content[:note_idx].strip()
        note_idx = content.find('\n[1]')
        if note_idx != -1:
            content = content[:note_idx].strip()
        
        f.write(content)
        f.write("\n")
        print(f"✓ 第{ch}章 已提取 ({len(content)} 字符)")

print("\n完成！")
