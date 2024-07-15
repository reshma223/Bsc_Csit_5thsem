<?php
// Check if the form is submitted to set the cookie
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];

    // Set a cookie named 'user' with the value of the entered username
    setcookie('user', $username, time() + 3600); // Cookie expires in 1 hour
}

// Check if the 'user' cookie is set
if (isset($_COOKIE['user'])) {
    $savedUsername = $_COOKIE['user'];
    $message = "Welcome back, $savedUsername!";
} else {
    $message = "Welcome! Enter your username below:";
    $savedUsername = '';
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cookie Example</title>
</head>
<body>
    <h2><?php echo $message; ?></h2>

    <?php if (!isset($_COOKIE['user'])) : ?>
        <form method="post" action="">
            <label for="username">Username:</label>
            <input type="text" id="username" name="username" value="<?php echo $savedUsername; ?>" required>
            <input type="submit" value="Submit">
        </form>
    <?php endif; ?>
</body>
</html>
