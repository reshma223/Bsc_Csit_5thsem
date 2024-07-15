<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get form data
    $name = $_POST["name"];
    $address = $_POST["address"];
    $phone = $_POST["phone"];
    $age = $_POST["age"];
    $gender = $_POST["gender"];

    // Database connection details
    $servername = "your_database_server";
    $username = "your_database_username";
    $password = "your_database_password";
    $dbname = "students_db";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // Insert data into the database
    $sql = "INSERT INTO students (name, address, phone, age, gender) VALUES ('$name', '$address', '$phone', '$age', '$gender')";

    if ($conn->query($sql) === TRUE) {
        echo "Record inserted successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
} else {
    echo "Invalid request";
}
?>
