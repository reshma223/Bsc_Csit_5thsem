$xmlData = '<?xml version="1.0" encoding="UTF-8"?><br>
<book>
    <title>Introduction to XML</title><br>
    <author>John Doe</author><br>
    <isbn>1234567890</isbn><br>
    <publisher>XYZ Publications</publisher><br>
    <edition>1st Edition</edition><br>
    <price>29.99</price><br>
</book>';

file_put_contents('book.xml', $xmlData);
