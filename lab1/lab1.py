# -*- coding: utf-8 -*-
#Полозова лаб.1


import urllib, urlparse, re


url = "http://plast.me/plastic/13077-ktulhu.html"
content = urllib.urlopen(url).read()
Urls_of_img = re.findall('img .*?src="(.*?)"', content)
AbsUrls =[]
try:
    for urls in Urls_of_img:
        AbsUrls.append(urlparse.urljoin(url, urls))
    for urls in AbsUrls:
        name = urls.rsplit('/',1)[1]
        urllib.urlretrieve(urls, name)
except:
    print 'err'
