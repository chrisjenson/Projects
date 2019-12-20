# frozen_string_literal: true

##
# Condensed migrations.
# Existing migrations were redesigned for simplicity and readability.
# Changed to RoR primary key behavior (implied id field).
# Implemented fk indexing.
#
# **Notes for learners**: Indexes are just a dictionary
# Postgres uses to make lookup of entries faster.
#
# There is an implied column named id. It's
# automatically assigned, automatically increased, and
# always unique. This is what's used by the foreign
# keys below by default.
class DbInit < ActiveRecord::Migration[5.2]
  def change
    # interest tags
    create_table 'tags' do |t|
      t.string 'name'
      t.boolean 'approved', null: false, default: false

      t.timestamps
    end

    # Community issues
    create_table 'issue_areas' do |t|
      t.string 'name', limit: 75, null: false

      t.timestamps
    end

    # Organizations
    create_table 'organizations' do |t|
      t.integer 'user_id', null: false # foreign key for: 'user'
      t.string 'name', limit: 75, null: false
      t.string 'email', limit: 50, null: false
      t.string 'phone_no', limit: 12, null: false
      t.string 'address', limit: 100
      t.string 'city', limit: 100
      t.string 'state', limit: 2
      t.string 'zip_code', limit: 5
      t.string 'description', limit: 1000
      t.boolean 'approved', null: false, default: false
      t.string 'issue_area', limit: 500

      t.timestamps
    end

    # Service opportunities
    create_table 'opportunities' do |t|
      t.bigint 'organization_id', null: false # foreign key for: 'user'
      t.string  'name',           limit: 50,  null: false
      t.string  'address',        limit: 100, null: false
      t.string  'city',           limit: 100, null: false
      t.string  'state',          limit: 2,   null: false
      t.string  'zip_code',       limit: 5,   null: false
      t.boolean 'transportation',             null: false
      t.string  'description',    limit: 500
      t.string  'frequency',      limit: 50
      t.string  'email',          limit: 50, null: false
      t.bigint 'issue_area_id' # foreign key for: 'issue_area'
      t.bigint 'tag_id' # foreign key for: 'tag'
      t.boolean 'approved', default: false
      t.date    'on_date'
      t.time    'start_time'
      t.time    'end_time'

      t.index 'tag_id'
      t.index 'issue_area_id'
      t.index 'organization_id'

      t.timestamps
    end

    create_table :favorite_opportunities do |t|
      t.references :user, foreign_key: true
      t.references :opportunity, foreign_key: true

      t.timestamps
    end

    create_table :favorite_organizations do |t|
      t.references :user, foreign_key: true
      t.references :organization, foreign_key: true

      t.timestamps
    end

    # add tag data to users (for organizations)
    add_column 'users', 'tag_id', :integer
    add_column 'users', 'admin', :boolean, default: false

    # Foreign key relations
    add_foreign_key 'users', 'tags', column: 'tag_id'
    add_foreign_key 'organizations', 'users', column: 'user_id'
    add_foreign_key 'opportunities', 'organizations', column: 'organization_id'
    add_foreign_key 'opportunities', 'tags', column: 'tag_id'
    add_foreign_key 'opportunities', 'issue_areas', column: 'issue_area_id'
  end
end