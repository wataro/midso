import argparse
import yaml
from pprint import pprint

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('yaml_path')
    args = parser.parse_args()
    with open(args.yaml_path) as f:
        contents = yaml.load(f)
        pprint(contents)

if __name__ == '__main__':
    main()
    
