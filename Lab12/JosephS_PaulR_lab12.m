%Create a program that graphs the total income for a male and female given
%the circumstances of their salary, years they worked, and the age they
%are currently to see their projected income.

salary = input('Please enter your salary');
num_years = input('Please enter desired amount of years');
age = input('Please enter your age');

age_inc = age;

%percent = []

%From our research, we found that at the age of 20 the average pay gap was
%10 percent, and by 55 it was around 25 percent and constant from there. We
%have a function that runs for each year. It will calculate the percentage
%the female gap is at that age compared to the male.
for i = 1:num_years
    if(age_inc > 20 && age_inc < 55)
        j = (age_inc - 20);
        percent(i) = .90 - (.004286 * j);
    end
    if(age_inc <= 20)
        percent(i) = .90;
    end
    if(age_inc >= 55)
        percent(i) = .75;
    end
    age_inc = age_inc + 1;
end

%Creating x for the numer of years worked, y for the income of the male,
%z for the female income, and w is the adjusted years from the start of
%their age.
x = 1:num_years;
y = x*salary;
z = percent(x) .* x * salary;

w = (age + x) - 1;

%This plots out our graph of the age gap. Anything between 0-20 years of
%age should be a constant 10 percent pay gap, and 55 and on should be a
%constant 25 percent pay gap. Between 20-55 we should see a curve getting
%farther from the male income.

figure(); % give us a window to plot in
plot(w, y,'-b','LineWidth',2);
hold on;
plot(w, z, '--g', 'LineWidth', 2);
xlabel('Age');
ylabel('Total Income');
%xlim([]);
legend('Men', 'Women', 'Location', 'best');
set(gca, 'FontSize', 20);