[![Codacy Badge](https://api.codacy.com/project/badge/Grade/ec121ba6ca61445483fb0017e526acf1)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=TCNJSwEngg/servd&amp;utm_campaign=Badge_Grade)
# SERVD
Web application for the Community Engaged Learning (CEL) administrators, local community service organizations, and college students to list, manage, and volunteer for upcoming opportunities in the local area.

## Development Setup

### Install Ruby on Rails & PostgreSQL for your machine:
Ruby (2.6.4) & Rails (5.2.3): 
https://gorails.com/setup/

> **TCNJ students using a VM:** In the installruby.sh file, change the ruby and rails versions accordingly!

### Install this repository: 

    git clone https://github.com/TCNJSwEngg/servd.git

Once cloned, navigate to the servd/code directory and install the project dependencies. 

    bundle install
    
If you encounter errors, try restarting PostgreSQL and installing additional updates.

For CentOS:
```sh
$ systemctl restart postgresql-9.6
$ sudo yum install postgresql96-libs
$ sudo yum install postgresql96-devel
```
For MacOS:
```sh
$ pg_ctl -D /usr/local/var/postgres start
   ```
> **TCNJ NOTE:** If issues continue, there's something wrong with your psql installation.

PLease run the following. `sudo yum install postgresql-libs postgresql-devel`

If the still continue, look up the error you're recieving for more advice.

### Create the databases and perform migration:

    rake db:create
    rake db:migrate:reset
    rake db:migrate
    rake db:seed

### Finally, run the app.
Find the correct binding for your VM if you're using one. Use the `--binding` flag or you won't be able to view the site from your browser.

    rails s (or rails server)
    
The app should be available in the browser at [localhost:3000](localhost:3000).

### Administration

To access the admin interface, go to the /admin page. It's powered by rails admin. (A remake of django-admin)
