import graphviz
import sys
import requests

def getDependencies(package_name):
    url="https://pypi.org/pypi/{}/json"
    dependencies=requests.get(url.format(package_name)).json()
    print(url.format(package_name))
    return dependencies

def list_dict(graph,dicts,name, depth):

    for key,value in dicts.items():

        graph.edge(name,key)

        if type(dicts[key])==dict:
            list_dict(graph,dicts.get(key),key, depth+1)


def main(package_name):
    if len(package_name)!=0:
        dot=graphviz.Digraph('Dependencies')
        deps= getDependencies(package_name)

        list_dict(dot,deps,package_name, 0)
        print(dot.source)

        dot.render("C:/Users/KLINY-ПК/Desktop/.data/Учёба/3 семестр/Конфиг/DZ2/test.gv", view=True)


if __name__ == '__main__':
   main(sys.argv[1])
