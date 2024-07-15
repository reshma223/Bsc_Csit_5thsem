<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieving values from the form
    $name = $_POST["name"];
    $email = $_POST["email"];
    $gender = isset($_POST["gender"]) ? $_POST["gender"] : "Not specified";
    $city = $_POST["city"];
    $subscribe = isset($_POST["subscribe"]) ? "Yes" : "No";

    // Displaying the values
    echo "<h2>User Input Summary</h2>";
    echo "<p><strong>Name:</strong> $name</p>";
    echo "<p><strong>Email:</strong> $email</p>";
    echo "<p><strong>Gender:</strong> $gender</p>";
    echo "<p><strong>City:</strong> $city</p>";
    echo "<p><strong>Subscribe to Newsletter:</strong> $subscribe</p>";
} else {
    // If the form is not submitted through POST method
    echo "<p>No data submitted.</p>";
}
?>
