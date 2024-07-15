<?php

// Dummy user data for demonstration purposes
$users = array(
    'user1' => 'password1',
    'user2' => 'password2'
);

// Function to validate user credentials
function validateUser($username, $password, $users) {
    if (array_key_exists($username, $users) && $users[$username] === $password) {
        return true;
    } else {
        return false;
    }
}

// Check if the form is submitted
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Validate user credentials
    if (validateUser($username, $password, $users)) {
        // Redirect to the welcome page if the credentials are correct
        header('Location: welcome.php?username=' . $username);
        exit();
    } else {
        // Print an error message if the credentials are incorrect
        $error_message = 'Invalid username or password. Please try again.';
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Page</title>
</head>
<body>
    <h2>Login</h2>
    <?php if (isset($error_message)) : ?>
        <p style="color: red;"><?php echo $error_message; ?></p>
    <?php endif; ?>
    <form method="post" action="">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" required><br>

        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required><br>

        <input type="submit" value="Login">
    </form>
</body>
</html>
