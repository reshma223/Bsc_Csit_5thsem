$xmlData = '<?xml version="1.0" encoding="UTF-8"?><br>
<employee>
    <name>name: John Doe</name>
    <address>address: 123 Main Street, Cityville</address>
    <phone>phone: 123-456-7890</phone><br>
    <designation>designation: Software Engineer</designation><br>
    <salary>salary: 60000</salary><br>
</employee>';

file_put_contents('employee.xml', $xmlData);
