import pygame

# Initialize Pygame
pygame.init()

# Set the window size and title
screen_width = 800
screen_height = 600
pygame.display.set_caption("Blood Sugar Monitor")

# Set the background color
bg_color = (255, 255, 255)

# Create a font for displaying the blood sugar level
font = pygame.font.Font(None, 36)

# Set the initial blood sugar level
blood_sugar = 100

# Run the game loop
running = True
while running:
    # Check for events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Update the blood sugar level (simulating a real-time measurement)
    blood_sugar += 1
    
    # Limit the blood sugar level to a range of 70-180
    blood_sugar = min(max(blood_sugar, 70), 180)

    # Render the blood sugar level text
    text = font.render(f"Blood Sugar: {blood_sugar}", True, (0, 0, 0))

    # Clear the screen
    screen.fill(bg_color)

    # Draw the text on the screen
    screen.blit(text, (50, 50))

    # Update the display
    pygame.display.update()

# Quit Pygame
pygame.quit()